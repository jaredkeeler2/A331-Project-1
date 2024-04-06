#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>

using namespace std; 

void heapify(int array[], int n, int i)
{
    int largest = i; // Initialize largest as root Since we are using 0 based indexing
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && array[l] > array[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && array[r] > array[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(array[i], array[largest]);

        // Recursively heapify the affected sub-tree
        heapify(array, n, largest);
    }
}

// main function to do heap sort
void heapSort(int array[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(array[0], array[i]);

        // call max heapify on the reduced heap
        heapify(array, i, 0);
    }
}

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

//creates a new dynamically allocated array, inserts the data from the current array file, and measures the execution time (in microseconds) of the heapSort function.
void compute(string filename) {
  int size = getSize(filename);
  int* array = new int[size];

  file2array(filename, array);

  //measures execution time in microseconds
  auto start = std::chrono::high_resolution_clock::now();
  heapSort(array, size);
  auto stop = std::chrono::high_resolution_clock::now();
  double duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();

  //converts microseconds to seconds
  duration *= 1e-6;

  //creates a new Log_HeapSort file
  ofstream newLog("Log_HeapSort.txt", std::ios::app);
  newLog << "Applying HeapSort to " << filename << "\nTime to sort: " << fixed << setprecision(6) << duration << " seconds\n" << endl;
  newLog.close();

  delete[] array;
}

int main() 
{  
  //clears any previous logs
  ofstream clearLog("Log_HeapSort.txt", std::ios::trunc);

  for (int i = 0; i < 10; i++) {
    compute("Array_" + to_string(i + 1) + ".txt");
  }

  return 0;
}