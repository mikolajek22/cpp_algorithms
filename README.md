# Data Structures, Algorithms & ADT Playbench

Implementation and visualization of sorting algorithms in C++ and Python.

## Abstract Data Types
1. Queue
2. Ring Queue
3. Stack
4. Linked List Stack
5. Binary Tree

## Searching Algorithms

|Algorithm|avg time|worst time|best time|space|
|:-------:|:-------:|:-------:|:-------:|:-------:|
|Linear Search|O(n)|O(n)|O(1)|O(1)|
|Binary Search|O(log(n))|OO(log(n))|O(1)|O(1)|

 
## Sorting Algorithms

|Algorithm|avg time|worst time|best time|space|
|:-------:|:-------:|:-------:|:-------:|:-------:|
|Bubble Sort|O(n<sup>2</sup>)|O(n<sup>2</sup>)|O(n)|O(1)|
|Selection Sort|O(n<sup>2</sup>)|O(n<sup>2</sup>)|O(n<sup>2</sup>)|O(1)|
|Insertion Sort|O(n<sup>2</sup>)|O(n<sup>2</sup>)|O(n)|O(1)|
|Merge Sort|O(nlog(n))|O(nlog(n))|O(nlog(n))|O(n)|
|Quick Sort|O(nlog(n))|O(n<sup>2</sup>)|O(nlog(n))|O(log(n))|
|Heap Sort|O(nlog(n))|O(nlog(n))|O(nlog(n))|O(log(n))|


<p align="center">
  <img src="Tests/sorting/data/benchmark.png" width="800"/>
</p>

## Build Sequence

### Algorithms and ADT

1. Get Google Test lib: `sudo apt install libgtest-dev`
2. Create and go to /build (from main folder):

    `mkdir build`

    `cd build`
3. Generate build files: `cmake ..`
4. Compie: `make`
5. Available tests:

    `./adt_test`

    `./searching_test` 

    `./sorting_test`

### Plots
1. Venv Build:

    `python -m venv venv`

    `source venv/bin/activate`

    `pip install -r requirements.txt`
2. Navigate to Tests/sorting: `cd Tests/sorting`
3. Run Python script: `python timeComparement.py`
4. Plots are in: `Tests/sorting/data`

