import os
import sys
import time

import BubbleSort
import HeapSort
import InsertionSort
import MergeSort
import QuickSort
import SelectionSort

#Generate Log Folders
main_dir = os.path.dirname(os.path.abspath(sys.argv[0]))
log_dir = main_dir + "\Logs"
if (os.path.exists(log_dir) == False):
    os.makedirs(log_dir)
algo_dirs = ["\Bubble", "\Heap", "\Insertion", "\Merge", "\Quick", "\Selection"]
for i in algo_dirs:
        if (os.path.exists(log_dir + i) == False):
            os.makedirs(log_dir + i)

def file2array(filename):
    array = []
    file = open(filename, "r")
    for i in file:
        array = i.split(",")
    return array

def compute(filename, sort_type, pass_num):
    data = file2array(filename)
    time_before = time.time()
    if (sort_type == "Bubble"):
        BubbleSort.BubbleSort(data)
        tempdir = log_dir + "\Bubble"
    if (sort_type == "Heap"):
        HeapSort.HeapSort(data)
        tempdir = log_dir + "\Heap"
    if (sort_type == "Insertion"):
        InsertionSort.InsertionSort(data)
        tempdir = log_dir + "\Insertion"
    if (sort_type == "Merge"):
        MergeSort.MergeSort(data)
        tempdir = log_dir + "\Merge"
    if (sort_type == "Quick"):
        QuickSort.QuickSort(data, 0, len(data) - 1)
        tempdir = log_dir + "\Quick"
    if (sort_type == "Selection"):
        SelectionSort.SelectionSort(data, len(data) - 1)
        tempdir = log_dir + "\Selection"
    time_after = time.time()
    time_diff = time_after - time_before
    logname = tempdir + "\Log_" + sort_type + "Sort_" + str(pass_num) + ".txt"
    try:
        compute_log = open(logname, "a")
    except:
        compute_log = open(logname, "w")
    log = "Applying " + sort_type + "Sort to " + filename + "\nSorted Array:\n"
    log += "Time to sort: " + str(time_diff) + "\n"
    compute_log.write(log)
    compute_log.close

num_passes = 2
num_arrays = 2
algo_types = ["Bubble", "Heap", "Insertion", "Merge", "Quick", "Selection"]
for i in algo_types:
    j = 1
    while j <= num_passes:
        k = 1
        while k <= num_arrays:
            compute(main_dir + "\Arrays\Array_" + str(k) + ".txt", i, j)
            k += 1
        j += 1