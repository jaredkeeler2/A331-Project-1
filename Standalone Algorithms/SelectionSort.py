import time
import sys

#sorting by finding min_index
def selectionSort(array, size):
    
    for ind in range(size):
        min_index = ind
 
        for j in range(ind + 1, size):
            # select the minimum element in every iteration
            if array[j] < array[min_index]:
                min_index = j
         # swapping the elements to sort the array
        (array[ind], array[min_index]) = (array[min_index], array[ind])
 
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
    selectionSort(data, size - 1)
    time_after = time.time()
    time_diff = time_after - time_before
    try:
        compute_log = open("Log_SelectionSort.txt", "a")
    except:
        compute_log = open("Log_SelectionSort.txt", "w")
    log = "Applying SelectionSort to " + filename + "\nSorted Array:\n"
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