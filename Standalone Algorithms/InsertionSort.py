import time
import sys

# Function to do insertion sort
def insertionSort(arr):
 
    # Traverse through 1 to len(arr)
    for i in range(1, len(arr)):
 
        key = arr[i]
 
        # Move elements of arr[0..i-1], that are
        # greater than key, to one position ahead
        # of their current position
        j = i-1
        while j >= 0 and key < arr[j] :
                arr[j + 1] = arr[j]
                j -= 1
        arr[j + 1] = key
 
 
def file2array(filename):
    array = []
    file = open(filename, "r")
    for i in file:
        array = i.split(",")
    return array

def compute(filename):
    data = file2array(filename)
    time_before = time.time()
    insertionSort(data)
    time_after = time.time()
    time_diff = time_after - time_before
    try:
        compute_log = open("Log_InsertionSort.txt", "a")
    except:
        compute_log = open("Log_InsertionSort.txt", "w")
    log = "Applying InsertionSort to " + filename + "\nSorted Array:\n"
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