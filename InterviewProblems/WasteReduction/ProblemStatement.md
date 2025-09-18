# Waste Reduction

## Problem Description

You work for a pharmaceutical company that produces liquid medicine. Patients require different amounts, and to package the medication, you can choose between several different sets of containers. Each container set specifies the sizes of containers it has available.

When fulfilling an order for a given amount, a single container must be used. If a container of the exact required size does not exist in a set, you must use the container with the next largest size available in that set. The extra medicine included in that larger container is considered waste.

Your job is to evaluate the different sets of containers and identify the single set that will minimize the total waste across a collection of orders.

## Task

Your goal is to determine which container set is the most efficient.

- For each individual requirement, find the best-fitting container from a given set. The best fit is the container with the smallest size that is greater than or equal to the required amount.
- The waste for a single requirement is calculated as: `(size of the chosen container) - (required amount)`.
- The total waste for a container set is the sum of the waste generated for all requirements.
- You must find the container set that produces the minimum possible total waste.
- If multiple sets result in the same minimum total waste, return the index of the set that appeared first (the lower index).
- If a container set cannot fulfill all requirements (for example, if a requirement is larger than the set's biggest container), that set is invalid.
- If no set can satisfy all requirements, return -1.

## Function Description

Complete the function `chooseContainers` in the editor.

### Function Signature:

```cpp
int chooseContainers(vector<int> requirements, int numContainerSets, vector<vector<int>> containers)
```

### Parameters:

- `requirements` (vector<int>): A list of integers representing the required amounts for different orders.
- `numContainerSets` (int): The total number of container sets available.
- `containers` (vector<vector<int>>): A 2D list where each inner list `[set_index, size]` indicates that a container of `size` is available in the set identified by `set_index`. The container sizes for each set are guaranteed to be sorted in ascending order.

### Returns:

- `int`: The index of the container set that minimizes total waste. If no set can fulfill all requirements, return -1.

## Constraints

- 1 ≤ n ≤ 10<sup>5</sup> (where n is the number of requirements)
- 1 ≤ numContainerSets ≤ 10<sup>4</sup>
- 1 ≤ totalNumContainers ≤ 10<sup>5</sup>
- 1 ≤ requirements[i] ≤ 10<sup>9</sup>
- 0 ≤ containers[i][0] < numContainerSets
- 0 ≤ containers[i][1] ≤ 10<sup>9</sup>

## Examples

### Sample Case 0

**Input:**

```
requirements = [4, 6]
numContainerSets = 2
containers = [[0, 5], [0, 7], [0, 10], [1, 4], [1, 10]]
```

**Output:**

```
0
```

**Explanation:**

First, let's group the containers by their set index:

- Set 0 has container sizes: `{5, 7, 10}`.
- Set 1 has container sizes: `{4, 10}`.

Now, calculate the total waste for each set:

**For Set 0:**

- To fulfill the 4 ml requirement, use the 5 ml container. Waste = `5 - 4 = 1`.
- To fulfill the 6 ml requirement, use the 7 ml container. Waste = `7 - 6 = 1`.
- Total waste for Set 0 = `1 + 1 = 2`.

**For Set 1:**

- To fulfill the 4 ml requirement, use the 4 ml container. Waste = `4 - 4 = 0`.
- To fulfill the 6 ml requirement, use the 10 ml container. Waste = `10 - 6 = 4`.
- Total waste for Set 1 = `0 + 4 = 4`.

Comparing the total waste, Set 0 (waste of 2) is better than Set 1 (waste of 4). Therefore, the function should return `0`.

### Sample Case 1

**Input:**

```
requirements = [10, 15]
numContainerSets = 3
containers = [[0, 11], [0, 20], [1, 11], [1, 17], [2, 12], [2, 16]]
```

**Output:**

```
1
```

**Explanation:**

- Set 0 `{11, 20}`: Waste = `(11 - 10) + (20 - 15) = 1 + 5 = 6`.
- Set 1 `{11, 17}`: Waste = `(11 - 10) + (17 - 15) = 1 + 2 = 3`.
- Set 2 `{12, 16}`: Waste = `(12 - 10) + (16 - 15) = 2 + 1 = 3`.

Both Set 1 and Set 2 have the minimum waste of 3. According to the tie-breaking rule, we must return the one with the lower index. Thus, the correct output is `1`.
