#pragma once
#include <iostream>
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