#include <iostream>
#include <vector>
#include "include/binary_search.h"
#include "include/lower_bound.h"
#include "include/upper_bound.h"
#include "include/recursive_binary_search.h"

using namespace std;

int main()
{
    vector<int> nums = {2, 5, 7, 8, 11, 12};
    int target = 8;

    binarySearchIterative(nums, target);
    int lb_index = lowerBound(nums, target);
    int ub_index = upperBound(nums, target);
    int rec_index = binarySearchRecursive(nums, 0, nums.size() - 1, target);

    std::cout << "Lower Bound Index: " << lb_index << std::endl;
    std::cout << "Upper Bound Index: " << ub_index << std::endl;
    std::cout << "Recursive Binary Search Index: " << rec_index << std::endl;

    return 0;
}