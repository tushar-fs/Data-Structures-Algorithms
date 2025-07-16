# Sliding Window Patterns 🖼️

The sliding window is a powerful technique for solving problems involving contiguous subarrays or substrings. Problems that can be solved with this approach can be categorized into three main patterns.

## 📏 1. Fixed-Size Window

This is the simplest pattern, used when the window size is predetermined.

- **Goal:** Find a **maximum**, **minimum**, or **average** value within a subarray of a given, fixed size `K`.
- **Keywords:** "of size K," "fixed length," "given size."
- **Behavior:** A window is expanded to size `K`. Then, it slides across the array one element at a time, maintaining its size by adding one element from the right and removing one from the left.

### Pseudocode Template

```cpp
// ... initializations ...
int current_window_value = 0;

// Build the first window
for (int i = 0; i < K; i++) {
    // Add arr[i] to the window
}

// Slide the window across the rest of the array
for (int i = K; i < n; i++) {
    // 1. Add the new element arr[i]
    // 2. Remove the old element arr[i - K]
    // 3. Update the overall result
}
```

---

## 📈 2. Dynamic-Size Window (Optimization)

This is the most common pattern, where the window grows and shrinks to find an optimal solution.

- **Goal:** Find the **longest** or **shortest** subarray that satisfies a given condition.
- **Keywords:** "**longest**," "**shortest**," "**minimum length**," "**maximum size**."
- **Behavior:** The `right` pointer always expands the window. The `left` pointer only shrinks the window when a condition is violated.

- ### The Monotonic Subarray Logic

  This pattern works because the property being tracked (e.g., sum, count of distinct characters) is **monotonic**. This simply means that as you expand the window, the property only changes in one predictable direction (it increases or stays the same).

  The key consequence is this: If expanding the window makes it invalid (e.g., `sum > target`), you are **guaranteed** that expanding it _further_ will never fix it. The only way to find a new valid window is to shrink it from the left. This predictable behavior allows the simple expand/shrink logic to work efficiently.

### Pseudocode Template

```cpp
int left = 0;
// ... initializations ...

for (int right = 0; right < n; right++) {
    // Add arr[right] to the window and update its state

    // While the window is invalid...
    while (/* condition is broken */) {
        // ...remove arr[left] from the window and shrink
        left++;
    }

    // Update the result (e.g., max_len = max(max_len, right - left + 1))
}
```

---

## 🔢 3. Dynamic-Size Window (Counting Exact Subarrays)

This is a specific sub-pattern used for counting problems where the monotonic logic from the previous pattern does not apply.

- **Goal:** **Count** the number of subarrays that satisfy an **exact** property (e.g., `sum == K` or `exactly K distinct elements`).
- **Keywords:** "count," "number of," "exactly K."
- **Behavior:** This pattern handles **non-monotonic** conditions where an invalid window might become valid again through further expansion. Because direct counting is complex, it uses a clever trick: the principle of inclusion-exclusion.

### The "At Most" Principle

**`count(exactly K) = count(atMost(K)) - count(atMost(K - 1))`**

Each `atMost()` function is implemented using the standard dynamic window from pattern #2.

### Pseudocode Template

```cpp
// Helper function using the pattern from #2
int countSubarraysAtMost(int K) {
    int left = 0, count = 0;
    // ... initializations ...

    for (int right = 0; right < n; right++) {
        // Add arr[right] to the window

        while (/* condition for 'at most K' is broken */) {
            // Shrink from left
            left++;
        }
        // The number of new valid subarrays ending at 'right' is (right - left + 1)
        count += (right - left + 1);
    }
    return count;
}

// Main function
int totalCount = countSubarraysAtMost(K) - countSubarraysAtMost(K - 1);
```
