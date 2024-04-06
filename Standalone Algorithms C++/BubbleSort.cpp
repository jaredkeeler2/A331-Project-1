#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>

using namespace std; 

void bubbleSort(int* array, int n) 
{ 
  int i, j; 
  for (i = 0; i < n - 1; i++) 

    //last i elements are already in place 
    for (j = 0; j < n - i - 1; j++) 
        if (array[j] > array[j + 1]) 
            swap(array[j], array[j + 1]); 
} 

//gets the total number of numbers in the array file to be used //in a dynamically allocated array
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
    return count;

    file.close();
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

//creates a new dynamically allocated array, inserts the data //from the current array file, and measures the execution time //of the bubbleSort function.
void compute(string filename) {
  int size = getSize(filename);
  int* array = new int[size];
  
  file2array(filename, array);

  //measures execution time in microseconds
  auto start = std::chrono::high_resolution_clock::now();
  bubbleSort(array, size);
  auto stop = std::chrono::high_resolution_clock::now();
  double duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();

  //converts microseconds to seconds
  duration *= 1e-6;
  
  //creates a new Log_BubbleSort file
  ofstream newLog("Log_BubbleSort.txt", std::ios::app);
  newLog << "Applying BubbleSort to " << filename << "\nTime to sort: " << fixed << setprecision(6) << duration << " seconds\n" << endl;
  newLog.close();

  delete[] array;
}

int main() 
{  
  //clears any previous logs
  ofstream clearLog("Log_BubbleSort.txt", std::ios::trunc);
  
  for (int i = 0; i < 10; i++) {
    compute("Array_" + to_string(i + 1) + ".txt");
  }

  return 0;
}