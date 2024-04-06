#include <iostream>
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