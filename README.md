# Alandr-QuickSort

fastIO uses the template for faster io provided by Simon, and although it is significantly faster locally, it gets TLE on
Kattis despite a basic scanf()/print() loop working. 

Timing is a program that takes times the sorting of an array, it takes the size of the array as the first command-line 
argument and the iterations to run as the second. The iterations are used soley to make sure a lucky shuffle doesn't screw
with the results.

## Timing

| Array Size | Iterations | Total Time  | Per sort       |
| ---------- | ---------- | ----------- | -------------- |
| 10         | 10000      | 0.003714s   | 0.371362µs     |
| 100        | 10000      | 0.026669s   | 2.666854µs     |
| 1000       | 10000      | 0.343012s   | 34.301160µs    |
| 10000      | 10000      | 4.470520s   | 447.051965µs   |
| 100000     | 10000      | 55.230149s  | 5523.014890µs  |


## Algorithm Specifics

The algorithm has no clever part to it, the pivot gets chosen as the first element in the subarray that's being sorted
because that is *marginally* faster than a random pivot. This leaves the code vulnerable to specially crafted
inputs that would make the running time n², but as long as it's dealing with random data `arr[0]` is as good as a random
pivot. Unfortunately this horrible complexity also applied to already sorted arrays.

The code keeps subdividing the array until the size is either one or two. If it's one the subarray is obviously sorted,
and if it's two it does a compare and maybe swap.