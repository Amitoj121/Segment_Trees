# Segment_Trees
This repository contains an implementation of a Segment Tree in C++. The Segment Tree is a versatile data structure that supports efficient range queries and updates. This implementation includes operations such as finding the maximum, minimum, bitwise OR, bitwise AND, and sum within a range, along with support for lazy propagation for range updates.
<br>
Files
1. Segment_Tree.h
This is the header file that contains the declaration of the Segment_Tree class and its member functions.
<br>
2. Segment_Tree.cpp
This file contains the definitions of the member functions declared in Segment_Tree.h. It includes the constructor and functions for building the tree, querying range values, and updating the tree.
<br>
3. test_case.cpp
This file contains the main function to test the Segment Tree. It includes interactive input for the user to perform various operations on the Segment Tree, such as:

Calculating the maximum in a given range.
Calculating the minimum in a given range.
Calculating the bitwise OR in a given range.
Calculating the bitwise AND in a given range.
Updating a value in the array.
Calculating the sum in a given range.
Performing range updates (only for sum calculation).
<br>
Compilation and Execution
<br>
To compile and Run the code,use following commands:
<br>
g++ -o test_case Segment_Tree.cpp test_case.cpp
<br> 
Run The Executable:
<br>
./test_case
<br>
Usage
When you run the test_case executable, you will be prompted to enter the size of the array and its elements. After building the Segment Tree, you can interactively perform the following operations:

Calculate the maximum in a given range.
Calculate the minimum in a given range.
Calculate the bitwise OR in a given range.
Calculate the bitwise AND in a given range.
Update a value in the array.
Calculate the sum in a given range.
Perform a range update (only affects the sum calculation).



