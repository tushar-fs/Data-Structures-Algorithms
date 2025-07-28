## Problem Description

In a company, an employee's earnings are determined by their work schedule. The rules are as follows:

1.  **Fixed Pay:** The employee receives a fixed amount, `fixedPay`, for each day they work.
2.  **Consecutive Bonus:** They also receive an additional `bonus` if they work on a given day and had also worked on the immediately preceding day.

The employee is given an initial work schedule as a binary string, where `'1'` represents a workday and `'0'` represents a day off.

To increase their earnings, the employee has the option to change up to `k` of their days off ('0') to workdays ('1'). The challenge is to find the optimal way to use these `k` changes to achieve the absolute maximum total earnings.

---

## Function Signature

The solution is implemented in the following C++ function:

```cpp
int getMaxEarnings(std::string schedule, int k, int fixedPay, int bonus);
```

### Parameters:

- `std::string schedule`: A binary string of length `n` representing the work schedule.
- `int k`: The maximum number of days off ('0') that can be changed to workdays ('1').
- `int fixedPay`: The fixed pay for each workday.
- `int bonus`: The bonus for working on consecutive days.

### Returns:

- A integer representing the maximum possible earnings.

---

## Constraints

- `1 <= n <= 2 * 10^5` (where `n` is the length of `schedule`)
- `0 <= k <= n`
- `1 <= fixedPay, bonus <= 10^9`
- `schedule[i]` is either `'0'` or `'1'`.

---

## Examples

### Sample Case 0

**Input:**

- `schedule` = "10101"
- `k` = 2
- `fixedPay` = 4
- `bonus` = 3

**Explanation:**
The initial schedule has two gaps of '0's: `1(0)1` and `1(0)1`.
An optimal strategy is to use the `k=2` changes to fill both gaps, resulting in a new schedule of `"11111"`.

- **Initial Earnings (10101):**
  - Day 1: 4
  - Day 3: 4
  - Day 5: 4
  - Total = 12
- **Earnings from Changes:**
  - Change Day 2 to '1': +4 (fixed) + 3 (bonus with Day 1) + 3 (bonus with Day 3) = 10
  - Change Day 4 to '1': +4 (fixed) + 3 (bonus with Day 3) + 3 (bonus with Day 5) = 10
- **New Total Earnings:** 12 (initial) + 10 + 10 = 32.
  - _A simpler calculation for the new schedule "11111" is: (5 _ 4) + (4 _ 3) = 20 + 12 = 32._

**Sample Output 0:**

```
32
```

### Sample Case 1

**Input:**

- `schedule` = "1111001"
- `k` = 1
- `fixedPay` = 3
- `bonus` = 3

**Explanation:**
The schedule has one gap of two '0's: `1(00)1`. We have `k=1` change.
The optimal move is to change the '0' at index 4 to a '1', making the schedule `"1111101"`. This change connects to the existing '1' at index 3, yielding a bonus.

- **Earnings from change:** +3 (fixedPay) + 3 (bonus) = 6
- **Initial Earnings:** (5 _ 3) + (3 _ 3) = 15 + 9 = 24
- **New Total Earnings:** 24 + 6 = 30

**Sample Output 1:**

```
30
```
