import time
import sys

def heapify(arr, N, i):
    largest = i  # Initialize largest as root
    l = 2 * i + 1     # left = 2*i + 1
    r = 2 * i + 2     # right = 2*i + 2

    # See if left child of root exists and is
    # greater than root
    if l < N and arr[largest] < arr[l]:
        largest = l

    # See if right child of root exists and is
    # greater than root
    if r < N and arr[largest] < arr[r]:
        largest = r

    # Change root, if needed
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]  # swap

        # Heapify the root.
        heapify(arr, N, largest)

# The main function to sort an array of given size
def heapSort(arr):
    N = len(arr)

    # Build a maxheap.
    for i in range(N//2 - 1, -1, -1):
        heapify(arr, N, i)

    # One by one extract elements
    for i in range(N-1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]  # swap
        heapify(arr, i, 0)

def file2array(filename):
    array = []
    file = open(filename, "r")
    for i in file:
        array = i.split(",")
    return array

def compute(filename):
    data = file2array(filename)
    time_before = time.time()
    heapSort(data)
    time_after = time.time()
    time_diff = time_after - time_before
    try:
        compute_log = open("Log_HeapSort.txt", "a")
    except:
        compute_log = open("Log_HeapSort.txt", "w")
    log = "Applying HeapSort to " + filename + "\nSorted Array:\n"
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