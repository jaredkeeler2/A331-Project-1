#include <iostream>
using namespace std; 

void selectionSort(int array[], int n) 
{ 
    int i, j, min_idx; 

    //ne by one move boundary of unsorted subarray 
    for (i = 0; i < n - 1; i++) { 

        //find the minimum element in unsorted array 
        min_idx = i; 
        for (j = i + 1; j < n; j++) { 
            if (array[j] < array[min_idx]) 
                min_idx = j; 
        } 

        //swap the found minimum element with the first element 
        if (min_idx != i) 
            swap(array[min_idx], array[i]); 
    } 
}