# 🧠 Data Structures & Algorithms

[![Language](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)](#)
[![Language](https://img.shields.io/badge/Java-ED8B00?style=for-the-badge&logo=openjdk&logoColor=white)](#)
[![Language](https://img.shields.io/badge/JavaScript-F7DF1E?style=for-the-badge&logo=javascript&logoColor=black)](#)
[![Problems](https://img.shields.io/badge/Problems%20Solved-130+-blueviolet?style=for-the-badge)](#)

A comprehensive, well-organized collection of **130+ solutions** to data structures and algorithms problems — spanning core CS fundamentals, competitive programming patterns, and real-world interview questions.

> Built as a living reference for algorithm design, complexity analysis, and problem-solving fluency in **C++**, **Java**, and **JavaScript**.

---

## 📖 Table of Contents

| # | Topic | Problems | Highlights |
|---|-------|:--------:|------------|
| 1 | [Trees & BSTs](#-trees--binary-search-trees) | 42 | Traversals, Views, LCA, Serialize/Deserialize, Largest BST |
| 2 | [Graphs](#-graphs) | 19 | Dijkstra, Bellman-Ford, Floyd-Warshall, SCC, MST, Topological Sort |
| 3 | [Dynamic Programming](#-dynamic-programming) | 15 | Knapsack variants, Grid DP, LCS, Coin Change, Paint Houses |
| 4 | [Binary Search](#-binary-search) | 12 | Rotated Arrays, Peak Finding, Matrix Median, Nth Root |
| 5 | [Recursion & Backtracking](#-recursion--backtracking) | 10 | N-Queens, Rat in a Maze, Combination Sum, Word Square |
| 6 | [Interview Problems](#-interview-problems) | 10 | Real OA/interview problems with solutions |
| 7 | [Trie](#-trie) | 7 | Implementations, Max XOR, Distinct Substrings |
| 8 | [Linked Lists](#-linked-lists) | 3 | Reverse SLL/DLL, Flatten Multi-level List |
| 9 | [Stacks](#-stacks) | 3 | Next/Previous Greater & Smaller Elements, Min Stack |
| 10 | [Sliding Window](#-sliding-window) | 1 | Permutation in String |
| 11 | [Greedy](#-greedy) | 2 | Demand-Supply Pattern, Maximum Earning |
| 12 | [Cyclic Sort](#-cyclic-sort) | 2 | Cycle Sort, Find Missing Number |
| 13 | [Arrays](#-arrays) | 1 | Maximum Frequency in Range |
| 14 | [Math](#-math) | 1 | Binary Exponentiation |
| 15 | [JavaScript Polyfills](#-javascript-polyfills) | 1 | Native method re-implementations |

---

## 🌲 Trees & Binary Search Trees

Extensive coverage of tree-based problems using both iterative and recursive approaches.

<details>
<summary><b>Binary Tree Fundamentals</b></summary>

| Problem | File |
|---------|------|
| DFS Traversals (Pre/In/Post — Recursive & Iterative) | `tree_traversal.cpp`, `tree_traversals.cpp` |
| Level Order / BFS Traversal | `tree_traversals.cpp` |
| Height of Binary Tree | `height_of_tree.cpp` |
| Diameter of Binary Tree | `diameter_of_tree.cpp` |
| Balanced Binary Tree Check | `balanced_binary_tree.cpp` |
| Invert Binary Tree | `invert_binary_tree.cpp` |
| Count Nodes in Complete Tree | `count_nodes_in_complete_tree.cpp` |
| Check Complete Binary Tree | `check_complete_tree.cpp` |
| Construct Binary Tree from Traversals | `construct_binary_tree.cpp` |
| Count Connected Components (Number of Islands) | `connected_components.cpp` |

</details>

<details>
<summary><b>Tree Views & Orders</b></summary>

| Problem | File |
|---------|------|
| Left View | `left_view.cpp` |
| Right View | `right_view.cpp` |
| Top View | `top_view.cpp` |
| Bottom View | `bottom_view.cpp` |
| Vertical Order Traversal | `vertical_order_traversal.cpp` |
| Boundary Traversal | `boundry_traversal.cpp` |
| Maximum Width | `maximum_width.cpp` |

</details>

<details>
<summary><b>Advanced Tree Problems</b></summary>

| Problem | File |
|---------|------|
| Lowest Common Ancestor | `lowest_common_ancestor.cpp` |
| Maximum Path Sum | `maximum_path_sum.cpp` |
| Longest Increasing Path in Tree | `maximum_leanage_path.cpp` |
| Longest Consecutive Path | `longest_consecutive_path.cpp` |
| Longest Univalue Path | `longest_univalue_path.cpp` |
| Flatten to Linked List (Preorder) | `flatten_binary_tree_preorder.cpp` |
| Flatten to Linked List (Inorder) | `flatten_binary_tree_inorder.cpp` |
| Find Duplicate Subtrees | `find_duplicate_trees.cpp` |
| Expression Tree Evaluation | `expression_tree.cpp` |
| Serialize / Deserialize Tree | `TreeCodec.java` |

</details>

<details>
<summary><b>Binary Search Trees</b></summary>

| Problem | File |
|---------|------|
| Search in BST | `search_in_bst.cpp` |
| Insert Node in BST | `insert_node_bst.cpp` |
| Delete Node in BST | `delete_in_bst.cpp` |
| Construct BST from Preorder | `construct_bst.cpp` |
| Validate BST | `validate_bst.cpp` |
| LCA in BST | `lca_in_bst.cpp` |
| Floor in BST | `floor_in_bst.cpp` |
| Ceil in BST | `ceil_in_bst.cpp` |
| Recover BST | `recover_bst.cpp` |
| Largest BST in Binary Tree | `largestBST_in_tree.cpp` |
| BST Iterator | `BSTIterator.java` |
| BST Bidirectional Iterator | `BSTBidirectionalIterator.java` |
| Two Sum in BST | `TwoSum.java` |
| BST Codec (Serialize/Deserialize) | `BSTCodec.java` |

</details>

---

## 📈 Graphs

Covers all major graph algorithms — shortest paths, cycle detection, topological ordering, and connectivity.

| Problem | Algorithm / Technique | File |
|---------|----------------------|------|
| Build Adjacency List | Graph Representation | `build_graph.cpp` |
| Print All Paths | DFS | `print_all_paths.cpp` |
| Detect Cycle (Undirected — BFS) | BFS + Parent Tracking | `detect_cycle_bfs.cpp` |
| Detect Cycle (Undirected — DFS) | DFS + Parent Tracking | `detect_cycle_dfs.cpp` |
| Detect Cycle (Directed) | DFS + Recursion Stack | `detect_cycle_directed.cpp` |
| Bipartite Graph Check | BFS/DFS Coloring | `bipartite_graph.cpp` |
| Topological Sort | DFS-based | `topological_sort.cpp` |
| Kahn's Algorithm | BFS Topological Sort | `kahn_algorithm.cpp` |
| Shortest Path (Undirected) | BFS | `shortest_distance_undirected.cpp` |
| Shortest Path (DAG) | Topological Sort + Relaxation | `shortest_path_dag.cpp` |
| Dijkstra's Algorithm | Min-Heap / Priority Queue | `dijkstra.cpp` |
| Bellman-Ford Algorithm | Edge Relaxation | `bellman_ford.cpp` |
| Floyd-Warshall Algorithm | All-Pairs Shortest Path | `floyd_warshall.cpp` |
| Prim's MST ⏳ | Greedy + Priority Queue | `prims_mst.cpp` |
| Disjoint Set Union (by Rank) | Union-Find | `dsu_rank.cpp` |
| Strongly Connected Components | Kosaraju's Algorithm | `strongly_connected_components.cpp` |
| Rotten Oranges | Multi-source BFS | `Rotten_oranges.cpp` |
| Number of Distinct Islands | DFS + Hashing | `number_of_distinct_islands.cpp` |
| Word Ladder ⏳ | BFS Level-order | `word_ladder.cpp` |

---

## 💡 Dynamic Programming

Organized by sub-pattern for easy reference.

<details>
<summary><b>Grid / Matrix DP</b></summary>

| Problem | File |
|---------|------|
| Minimum Path Sum (LC #64) | `manimum_path.cpp` |
| Triangle Minimum Path (LC #120) | `triangle.cpp` |
| Unique Paths (LC #62) | `variant1.cpp` |
| Unique Paths with Obstacles (LC #63) | `variant2.cpp` |
| Cherry Pickup II — Max Fruits with Two Players (LC #1463) | `3Dgrid.cpp` |

</details>

<details>
<summary><b>Subsequences & Knapsack</b></summary>

| Problem | File |
|---------|------|
| 0/1 Knapsack | `knapsack.cpp` |
| Unbounded Knapsack | `unbounded_knapsack.cpp` |
| Coin Change — Minimum Coins (LC #322) | `minimum_coins.cpp` |
| Subset Sum Problem | `find_target_sum.cpp` |
| Target Sum — Assign +/- Signs (LC #494) | `assign_sign.cpp` |

</details>

<details>
<summary><b>Strings</b></summary>

| Problem | File |
|---------|------|
| Longest Common Subsequence | `longest_common_subsequences.cpp` |

</details>

<details>
<summary><b>Other DP</b></summary>

| Problem | File |
|---------|------|
| Ninja Training / Paint Houses — Memoization | `memoization.cpp` |
| Ninja Training / Paint Houses — Tabulation | `tabulation.cpp` |
| Frog Jump with K Steps | `DP-3.cpp` |

</details>

---

## 🔍 Binary Search

All problems leverage the binary search paradigm on sorted or monotonic data.

| Problem | File |
|---------|------|
| Iterative Binary Search | `binary_search.cpp` |
| Recursive Binary Search | `recursive_binary_search.cpp` |
| Lower Bound | `lower_bound.cpp` |
| Upper Bound | `upper_bound.cpp` |
| First & Last Occurrence | `first_and_last_occurance.cpp` |
| Search in Sorted Rotated Array | `search_In_sorted_rotated_array.cpp` |
| Find Peak Element (1D) | `find_peak_element.cpp` |
| Find Peak Element (2D Matrix) | `peak_element_matrix.cpp` |
| Single Non-Duplicate in Sorted Array | `single_non_duplicate.cpp` |
| Nth Root of Integer | `nth_root.cpp` |
| Square Root with Precision | `precise_sqrt_number.cpp` |
| Median in Row-wise Sorted Matrix | `median_in_matrix.cpp` |

---

## 🔄 Recursion & Backtracking

| Problem | File |
|---------|------|
| Combination Sum | `combination_sum.cpp` |
| Combination Sum II | `combination_sum_2.cpp` |
| Unique Permutations | `unique_permutations.cpp` |
| Palindrome Partitioning | `palindrome_partitioning.cpp` |
| N-Queens | `n_queens.cpp` |
| N-Queens (2nd Approach) | `n_queens_2_approach.cpp` |
| Rat in a Maze | `rat_in_maze.cpp` |
| Word Square | `word_square.cpp` |
| Print First Subset with Sum K | `print_first_result.cpp` |
| Merge Sort | `merge_sort.cpp` |

---

## 🏢 Interview Problems

Real coding assessment and interview questions with clean, documented solutions.

| Problem | Description |
|---------|-------------|
| [Waste Reduction](InterviewProblems/WasteReduction/) | Choose optimal container sets to minimize waste |
| [Apartment Hunting](InterviewProblems/ApartmentHunting/) | Find the best apartment location minimizing max distance to facilities |
| [Conference Room Booker](InterviewProblems/ConferenceRoomBooker/) | Schedule meetings across conference rooms |
| [Course Allotment](InterviewProblems/CourseAllotment/) | Assign courses to students optimally |
| [Task Allotment](InterviewProblems/TaskAllotment/) | Distribute tasks efficiently |
| [Organization Restructuring](InterviewProblems/OrganizationRestructuring/) | Tree-based org hierarchy problem |
| [Piano Player](InterviewProblems/PianoPlayer/) | Finger placement optimization |
| [String Buddies](InterviewProblems/StringBuddies/) | String transformation / matching |
| [File Size](InterviewProblems/FileSize/) | File system size computation |
| [Volunteers](InterviewProblems/Volunteers/) | Volunteer assignment problem |

---

## 🔤 Trie

| Problem | File |
|---------|------|
| Trie Implementation (C++) | `TrieImpl1/TrieImpl.cpp` |
| Trie Implementation (Java — v1) | `TrieImpl1/TrieImpl.java` |
| Trie Implementation (Java — v2) | `TrieImpl2/TrieImpl.java` |
| Count Distinct Rows in Binary Matrix | `Problems/CountDistinctRowsInBinaryMatrix/solution.cpp` |
| Longest Word with All Prefixes | `Problems/LongestWordWithAllPrefixes/Solution.java` |
| Maximum XOR | `Problems/MaximumXOR/solution.cpp` |
| Number of Distinct Substrings | `Problems/NumberOfDistinctSubstrings/Solution.java` |

---

## 🔗 Linked Lists

| Problem | File |
|---------|------|
| Reverse Singly Linked List | `reverseLL.cpp` |
| Reverse Doubly Linked List | `reverseDLL.cpp` |
| Flatten Multi-level Linked List | `flatten_linked_list.cpp` |

---

## 📚 Stacks

| Problem | File |
|---------|------|
| Previous & Next Greater Element | `find_pge_and_nge.cpp` |
| Previous & Next Smaller Element | `find_pse_and_nse.cpp` |
| Min Stack | `minStack.cpp` |

---

## 🪟 Sliding Window

| Problem | File |
|---------|------|
| Permutation in String (LC #567) | `stringMatching.cpp` |

---

## 💰 Greedy

| Problem | File |
|---------|------|
| Demand-Supply Pattern (LC 659) | `DemandSupplyPattern/Leetcode659.cpp` |
| [Maximum Earning](GreedyProblems/MaximumEarning/) | `MaximumEarning/solution.cpp` |

---

## 🔢 Cyclic Sort

| Problem | File |
|---------|------|
| Cycle Sort | `cycleSort.cpp` |
| Find Missing Number | `findMissingNumber.cpp` |

---

## 📐 Arrays

| Problem | File |
|---------|------|
| Maximum Appearing Element in Ranges (Prefix Sum) | `MaximumFreqInRange.cpp` |

---

## ➗ Math

| Problem | File |
|---------|------|
| Binary Exponentiation (Fast Power) | `binary_exponentiation.cpp` |

---

## 🌐 JavaScript Polyfills

| Problem | File |
|---------|------|
| Native Method Re-implementations | `jsCode.js` |

---

## 🗂️ Repository Structure

```
.
├── Arrays/                     # Array-based problems
├── BinarySearchAlgorithms/     # Binary search variants & applications
├── CyclicSortProblems/         # Cyclic sort pattern
├── DynamicProgramming/         # DP organized by sub-pattern
│   ├── Grid/
│   ├── PaintHouses/
│   ├── Strings/
│   └── Subsequences/
├── Graphs/                     # All major graph algorithms
├── GreedyProblems/             # Greedy approach problems
├── InterviewProblems/          # Real interview & OA questions
│   ├── ApartmentHunting/
│   ├── ConferenceRoomBooker/
│   ├── WasteReduction/
│   └── ...
├── JavaScript Polyfills/       # JS native method polyfills
├── LinkedList/                 # Linked list problems
├── MathAlgorithms/             # Number theory & math
├── Recursion/                  # Backtracking & recursion
├── SlidingWindow/              # Sliding window technique
├── Stacks/                     # Stack-based problems
├── TreesAlgorithms/            # Binary trees & BSTs
│   └── BinarySearchTrees/
├── Trie/                       # Trie implementations & problems
│   ├── TrieImpl1/
│   ├── TrieImpl2/
│   └── Problems/
└── README.md
```

---

## 🛠️ Tech Stack

| Language | Use Case |
|----------|----------|
| **C++** | Primary language — STL, templates, memory-efficient solutions |
| **Java** | BST iterators, Trie problems, Tree serialization |
| **JavaScript** | Polyfills and language internals |

---

## 🚀 How to Run

```bash
# C++ (compile & run)
g++ -std=c++17 -o solution <file>.cpp && ./solution

# Java
javac <File>.java && java <File>

# JavaScript
node <file>.js
```

---

<p align="center">
  <i>Continuously growing — new problems and patterns added regularly.</i>
</p>
