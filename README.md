# Advanced Sorting and Binary Heap Project

## Project Overview
This project implements various sorting algorithms, priority queue operations, and binary heap functions in C++. It is designed to demonstrate efficient sorting techniques, the use of a priority queue, and essential binary heap operations, complete with performance timing for each sorting algorithm.

## Features

### Sorting Algorithms
- **Shell Sort**: A gap-based sorting algorithm that performs faster than simple insertion sort for larger datasets. The implementation measures the time taken to sort.
- **Quicksort**: A divide-and-conquer algorithm that partitions an array and recursively sorts each part. Custom partition logic is used here.
- **Dijkstra’s 3-Way Partition Quicksort**: Partitions the array into three parts based on a pivot, optimized for cases with many duplicate elements.

### Priority Queue Operations
- **Ordered Array Queue**: A priority queue implemented using a sorted array. Elements are inserted in sorted order.
- **Binary Heap Queue**: A priority queue implemented using a binary heap structure.

### Binary Heap Functions
- **Heap Construction**: Builds a binary heap (max-heap) from an unordered array of integers.
- **Height Calculation**: Calculates the height of the heap based on the number of elements.
- **Leaf Count**: Computes the number of leaves in the heap.
- **Element Lookup**: Checks if a specific element exists within the heap.

### Utility Functions
- **Print Functions**: For displaying the sorted array or priority queue.
- **Placeholder Tree Functions**: (e.g., `samelevel`, `descendant`, `isheap`) – currently placeholders, intended for future binary tree functionality.
