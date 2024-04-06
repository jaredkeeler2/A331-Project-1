#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>

using namespace std; 

int partition(int array[], int low, int high)
{
  //choose the pivot

  int pivot = array[high];
  //index of smaller element and indicate the right position 
  //of pivot found so far
  int i = (low - 1);

  for(int j = low; j <= high; j++)
  {
    //if current element is smaller than the pivot
    if(array[j] < pivot)
    {
      //increment index of smaller element
      i++;
      swap(array[i], array[j]);
    }
  }
  swap(array[i + 1], array[high]);
  return (i + 1);
}

void quickSort(int array[], int low, int high)
{
  //when low is less than high
  if(low < high)
  {
    //pi is the partition return index of pivot

    int pi = partition(array, low, high);

    //smaller element than pivot goes left and
    //higher element goes right
    quickSort(array, low, pi-1);
    quickSort(array, pi+1, high);
  }
}

//gets the total number of numbers in the array file to be //used in a dynamically allocated array
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

//creates a new dynamically allocated array, inserts the data //from the current array file, and measures the execution time //of the quickSort function.
void compute(string filename) {
  int size = getSize(filename);
  int* array = new int[size];

  file2array(filename, array);

  //measures execution time in microseconds
  auto start = std::chrono::high_resolution_clock::now();
  quickSort(array, 0, size - 1);
  auto stop = std::chrono::high_resolution_clock::now();
  double duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();

  //converts microseconds to seconds
  duration *= 1e-6;

  //creates a new Log_QuickSort file
  ofstream newLog("Log_QuickSort.txt", std::ios::app);
  newLog << "Applying QuickSort to " << filename << "\nTime to sort: " << fixed << setprecision(6) << duration << " seconds\n" << endl;
  newLog.close();

  delete[] array;
}

int main() 
{  
  //clears any previous logs
  ofstream clearLog("Log_QuickSort.txt", std::ios::trunc);

  for (int i = 0; i < 10; i++) {
    compute("Array_" + to_string(i + 1) + ".txt");
  }

  return 0;
}