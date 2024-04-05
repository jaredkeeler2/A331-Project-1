import time
import sys

def mergeSort(myList):
    if len(myList) > 1:
        mid = len(myList) // 2
        left = myList[:mid]
        right = myList[mid:]

        # Recursive call on each half
        mergeSort(left)
        mergeSort(right)

        # Two iterators for traversing the two halves
        i = 0
        j = 0
        
        # Iterator for the main list
        k = 0
        
        while i < len(left) and j < len(right):
            if left[i] <= right[j]:
              # The value from the left half has been used
              myList[k] = left[i]
              # Move the iterator forward
              i += 1
            else:
                myList[k] = right[j]
                j += 1
            # Move to the next slot
            k += 1

        # For all the remaining values
        while i < len(left):
            myList[k] = left[i]
            i += 1
            k += 1

        while j < len(right):
            myList[k]=right[j]
            j += 1
            k += 1

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
    mergeSort(data)
    time_after = time.time()
    time_diff = time_after - time_before
    try:
        compute_log = open("Log_MergeSort.txt", "a")
    except:
        compute_log = open("Log_MergeSort.txt", "w")
    log = "Applying MergeSort to " + filename + "\nSorted Array:\n"
    #log += ",".join(data) + "\n"
    log += "Time to sort: " + str(time_diff) + "\n"
    compute_log.write(log)
    compute_log.close

sys.setrecursionlimit(200000)

num_arrays = 10
i = 1
while (i <= num_arrays):
    compute("array_" + str(i) + ".txt")
    i += 1