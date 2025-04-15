# Binary Search Implementations

This repository contains C++ implementations of various binary search algorithms.

## Implementations

* **Iterative Binary Search:** Finds the index of a target value in a sorted array using an iterative approach.
* **Recursive Binary Search:** Finds the index of a target value in a sorted array using a recursive approach.
* **Lower Bound:** Finds the index of the first element in a sorted array that is greater than or equal to the target value.
* **Upper Bound:** Finds the index of the first element in a sorted array that is greater than the target value.

## Usage

To use these implementations, you can include the header files in your C++ projects and call the respective functions.

## Example

```cpp
#include <iostream>
#include <vector>
#include "include/binary_search.h" // Include the header

int main() {
    std::vector<int> nums = {2, 5, 7, 8, 11, 12};
    int target = 8;
    binarySearchIterative(nums, target); // Use the function
    return 0;
}
