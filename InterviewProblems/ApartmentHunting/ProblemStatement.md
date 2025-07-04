# Apartment Hunting Problem

## 📝 Problem Statement

You're looking for a new apartment on a street where each block of apartments has a different set of amenities. You have a list of required amenities that you absolutely need.

Your goal is to find the apartment block that is the most optimal choice. The "best" block is defined as the one that **minimizes the farthest distance** you have to walk to access all of your required amenities.

For example, if you live in Block `X`, you might need to walk 2 blocks to the nearest gym, 0 blocks for a school (if it's in Block `X`), and 3 blocks to the nearest store. The farthest you'd have to walk is 3 blocks. You want to find the block where this "farthest walk" value is the smallest.

---

## 📥 Input Format

1.  `blocks`: A list of apartment blocks. In C++, this can be a `std::vector<std::unordered_map<std::string, bool>>`.
2.  `requirements`: A list of strings representing the amenities you require. In C++, a `std::vector<std::string>`.

---

## 📤 Output Format

Return an integer representing the zero-based `index` of the most optimal apartment block. If there's a tie, return the block with the lower index.

---

## 🧪 Example Test Case

### Input Data:

**`blocks`:**

```json
[
  { "gym": true, "school": false, "store": false, "park": false },
  { "gym": false, "school": true, "store": false, "park": false },
  { "gym": false, "school": false, "store": false, "park": true },
  { "gym": false, "school": false, "store": true, "park": false },
  { "gym": false, "school": true, "store": true, "park": false },
  { "gym": false, "school": false, "store": false, "park": false },
  {
    "gym": false,
    "school": false,
    "store": false,
    "park": false,
    "pool": true
  },
  { "gym": true, "school": false, "store": false, "park": false }
]
```

**`requirements`:**

```json
["gym", "store", "park"]
```

### Expected Output:

```
1
```

### 🚶 Walkthrough & Analysis

We must find the "score" (the farthest distance to a required amenity) for each block.

| Block Index | `dist to gym` | `dist to store` | `dist to park` | **Max Distance (Score)** |
| :---------: | :-----------: | :-------------: | :------------: | :----------------------: |
|      0      |       0       |        3        |       2        |          **3**           |
|      1      |       1       |        2        |       1        |          **2**           |
|      2      |       2       |        1        |       0        |          **2**           |
|      3      |       3       |        0        |       1        |          **3**           |
|      4      |       3       |        0        |       2        |          **3**           |
|      5      |       2       |        1        |       3        |          **3**           |
|      6      |       1       |        2        |       4        |          **4**           |
|      7      |       0       |        3        |       5        |          **5**           |

The lowest score is `2`, which occurs at both **Block 1** and **Block 2**. Since we return the one with the lower index in case of a tie, the correct answer is `1`.

---

## 💻 Solution Files

- `solution.cpp`: Optimized $O(b \cdot r)$ solution.
- `brute_force.cpp`: $O(b^2 \cdot r)$ brute-force solution for comparison.
