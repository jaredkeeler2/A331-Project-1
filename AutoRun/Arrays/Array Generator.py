import os
import random
import sys

def arr_gen(arr_name, arr_len):
    arr_name = open(arr_name+".txt", "w")
    tempstr = ""
    i = 0
    while (i < arr_len):
        tempstr += str(random.randint(0, 50))
        if (i < arr_len - 1):
            tempstr += ","
        i += 1
    arr_name.write(tempstr)
    arr_name.close()

main_dir = os.path.dirname(os.path.abspath(sys.argv[0]))
increment_size = 2000
num_arrays = 10
i = 1
while (i <= num_arrays):
    arr_gen(main_dir + "\Array_" + str(i), i * increment_size)
    i += 1