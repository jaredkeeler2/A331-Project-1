#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <filesystem>

#include "BubbleSort.cpp"
#include "HeapSort.cpp"
#include "InsertionSort.cpp"
#include "MergeSort.cpp"
#include "QuickSort.cpp"
#include "SelectionSort.cpp"

int getSize(string filename);
void file2array(string filename, int* &array);
void compute(string filename);


using namespace std; 
namespace fs = std::filesystem;


//gets the total number of numbers in the array file to be used in a dynamically allocated array
int getSize(string filename) {
    ifstream file(filename);
    string line; 
    getline(file, line);

    int count = 0;
    istringstream iss(line);
    string number;
    while (getline(iss, number, ',')) {
        count++;
    }
    file.close();

    return count;

}

//reads the array file and stores the numbers in a dynamically allocated array
void file2array(string filename, int* &array) {
  ifstream file(filename);
  string line; 
  getline(file, line);

  istringstream iss(line);
  string number;
  int count = 0;
  while (getline(iss, number, ',')) {
      array[count++] = stoi(number);
  }

  file.close();
}

//creates a new dynamically allocated array, inserts the data from the current array file, and measures the execution time of the current sort algorithm.
void compute(string filename, string sortType, string logDir, int pass) {
  int size = getSize(filename);
  int* array = new int[size];
  string tempDir;

  file2array(filename, array);

  //measures execution time in microseconds
  auto start = std::chrono::high_resolution_clock::now();
  if (sortType == "Bubble") {
    bubbleSort(array, size);
    tempDir = logDir + "\\Bubble";
  }
  if (sortType == "Heap") {
    heapSort(array, size);
    tempDir = logDir + "\\Heap";
  }
  if (sortType == "Insertion") {
    insertionSort(array, size);
    tempDir = logDir + "\\Insertion";
  }
  if (sortType == "Merge") {
    mergeSort(array, 0, size - 1);
    tempDir = logDir + "\\Merge";
  }
  if (sortType == "Quick") {
    quickSort(array, 0, size - 1);
    tempDir = logDir + "\\Quick";
  }
  if (sortType == "Selection") {
    selectionSort(array, size);
    tempDir = logDir + "\\Selection";
  }
  auto stop = std::chrono::high_resolution_clock::now();
  double duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();

  //converts microseconds to seconds
  duration *= 1e-6;

  //creates a new log file
  string logName = tempDir + "\\Log_" + sortType + "Sort_" + to_string(pass) + ".txt";
  ofstream newLog(logName, std::ios::app);
  newLog << "Applying " << sortType << "Sort to " << filename << "\nTime to sort: " << fixed << setprecision(6) << duration << " seconds\n" << endl;
  newLog.close();
  delete[] array;
}

int main() 
{  
  //make "Logs" folder
  string mainDir = fs::current_path().string();
  string logDir = mainDir + "\\Logs";
  if (!fs::is_directory(logDir)) {
    fs::create_directory(logDir); 
  }
  //make each algorithm log folder
  string algoDirs[6] = {"\\Bubble", "\\Heap", "\\Insertion", "\\Merge", "\\Quick", "\\Selection"};
  for (int i = 0; i < 6; i++) {
    if (!fs::is_directory(logDir + algoDirs[i])) {
    fs::create_directory(logDir + algoDirs[i]); 
    }
  }

  string sortTypes[6] = {"Bubble", "Heap", "Insertion", "Merge", "Quick", "Selection"};


  //can edit numPasses and numArrays to create different number of logs and test different number of arrays
  int numPasses = 2;
  int numArrays = 10; //max numArrays = 10
  //clears any previous logs
  for (int type = 0; type < 6; type++) {
    for (int pass = 0; pass < numPasses; pass++) {
      for (int array = 0; array < numArrays; array++) {
        string logName = logDir + "\\" + sortTypes[type] + "\\Log_" + sortTypes[type] + "Sort_" + to_string(pass) + ".txt";
        ofstream clearLog(logName, std::ios::trunc);
      }
    }
  }

  string arrayDir = mainDir + "\\Arrays";
  for (int type = 0; type < 6; type++) {
    for (int pass = 0; pass < numPasses; pass++) {
      for (int array = 0; array < numArrays; array++) {
        compute(arrayDir + "\\Array_" + to_string(array + 1) + ".txt", sortTypes[type], logDir, pass);
      }
    }
  }

  return 0;
}