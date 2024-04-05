import time
import sys

def bubbleSort(arr):
    n = len(arr)
     
    # Traverse through all array elements
    for i in range(n):
        swapped = False
 
        # Last i elements are already in place
        for j in range(0, n-i-1):
 
            # Traverse the array from 0 to n-i-1
            # Swap if the element found is greater
            # than the next element
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
                swapped = True
        if (swapped == False):
            break

def file2array(filename):
    array = []
    file = open(filename, "r")
    for i in file:
        array = i.split(",")
    return array

def compute(filename):
    data = file2array(filename)
    time_before = time.time()
    bubbleSort(data)
    time_after = time.time()
    time_diff = time_after - time_before
    try:
        compute_log = open("Log_BubbleSort.txt", "a")
    except:
        compute_log = open("Log_BubbleSort.txt", "w")
    log = "Applying BubbleSort to " + filename + "\nSorted Array:\n"
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