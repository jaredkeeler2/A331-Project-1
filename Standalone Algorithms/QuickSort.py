import time
import sys

def partition(array, low, high):
    # choose the rightmost element as pivot
    pivot = array[high]
    # pointer for greater element
    i = low - 1
    # traverse through all elements
    # compare each element with pivot
    for j in range(low, high):
        if array[j] <= pivot:
            # If element smaller than pivot is found
            # swap it with the greater element pointed by i
            i = i + 1
            # Swapping element at i with element at j
            (array[i], array[j]) = (array[j], array[i])
    # Swap the pivot element with the greater element specified by i
    (array[i + 1], array[high]) = (array[high], array[i + 1])
    # Return the position from where partition is done
    return i + 1
# function to perform quicksort
 
def quickSort(array, low, high):
    if low < high:
 
        # Find pivot element such that
        # element smaller than pivot are on the left
        # element greater than pivot are on the right
        pi = partition(array, low, high)
 
        # Recursive call on the left of pivot
        quickSort(array, low, pi - 1)
 
        # Recursive call on the right of pivot
        quickSort(array, pi + 1, high)
 
def file2array(filename):
    array = []
    file = open(filename, "r")
    for i in file:
        array = i.split(",")
    return array

def compute(filename):
    data = file2array(filename)
    size = len(data)
    time_before = time.time()
    quickSort(data, 0, size - 1)
    time_after = time.time()
    time_diff = time_after - time_before
    try:
        compute_log = open("Log_QuickSort.txt", "a")
    except:
        compute_log = open("Log_QuickSort.txt", "w")
    log = "Applying QuickSort to " + filename + "\nSorted Array:\n"
    log += "Time to sort: " + str(time_diff) + "\n"
    compute_log.write(log)
    compute_log.close

sys.setrecursionlimit(200000)

num_arrays = 10
i = 1
while (i <= num_arrays):
    compute("array_" + str(i) + ".txt")
    i += 1