#include <iostream>
using namespace std; 

void bubbleSort(int* array, int n) { 
  int i, j; 
  for (i = 0; i < n - 1; i++) 

    //last i elements are already in place 
    for (j = 0; j < n - i - 1; j++) 
        if (array[j] > array[j + 1]) 
            swap(array[j], array[j + 1]); 
} 