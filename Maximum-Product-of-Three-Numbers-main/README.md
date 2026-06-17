# Maximum Product of Three Numbers in C++

This project demonstrates different approaches to solving the problem of finding the maximum product of three numbers in an integer array using C++.

---

# Problem Statement

We are given a non-empty array `A` consisting of `N` integers `(N ≥ 3)`.  
Each element in the array can be either positive or negative.

The goal is to find the maximum possible product of any three numbers in the array.

---

# Key Observation

The maximum product always comes from one of two cases:

1. Product of the three largest values in the array.
2. Product of the two smallest values (negative numbers) multiplied by the largest value.

This happens because:

```text
Negative × Negative = Positive
```

So, two very small negative values may produce a large positive result.

---

# Examples

| Input Array | Expected Output | Reason |
|---|---|---|
| `{2, 3, 4}` | `24` | `2 × 3 × 4 = 24` |
| `{6, 7, 8, 10}` | `560` | `7 × 8 × 10 = 560` |
| `{-10, -10, 5, 2}` | `500` | `-10 × -10 × 5 = 500` |

---

# Algorithm 1 — Sorting Approach (Non-Recursive)

## Idea

1. Sort the array using Bubble Sort.
2. Compute:
   - Product of the largest 3 values.
   - Product of the smallest 2 values and the largest value.
3. Return the maximum.

---

## Pseudo-code

```text
function MaxProductOfThree(A):

    BubbleSort(A)

    n ← length(A)

    product1 ← A[n-1] × A[n-2] × A[n-3]
    product2 ← A[0] × A[1] × A[n-1]

    return max(product1, product2)
```

---

## Bubble Sort Pseudo-code

```text
function BubbleSort(A):

    n ← length(A)

    for i from 0 to n-2 do:
        for j from 0 to n-i-2 do:

            if A[j] > A[j+1] then
                swap(A[j], A[j+1])

        end for
    end for
```

---

## Time & Space Complexity

| Operation | Complexity |
|---|---|
| Bubble Sort | `O(n²)` |
| Product Calculations | `O(1)` |
| Total Time Complexity | `O(n²)` |
| Space Complexity | `O(1)` |

---

# Algorithm 2 — Iterative Approach (Non-Recursive)

## Idea

Traverse the array only once while tracking:

- Largest 3 numbers
- Smallest 2 numbers

Then compute:

```text
max(
    max1 × max2 × max3,
    min1 × min2 × max1
)
```

---

## Pseudo-code

```text
function MaxProductIterative(A):

    max1 ← -∞
    max2 ← -∞
    max3 ← -∞

    min1 ← +∞
    min2 ← +∞

    for each x in A do:

        update max1, max2, max3

        update min1, min2

    end for

    product1 ← max1 × max2 × max3
    product2 ← min1 × min2 × max1

    return max(product1, product2)
```

---

## Time & Space Complexity

| Operation | Complexity |
|---|---|
| Single Traversal | `O(n)` |
| Extra Variables | `O(1)` |
| Total Time Complexity | `O(n)` |
| Space Complexity | `O(1)` |

---

# Algorithm 3 — Recursive Approach

## Idea

For each element, we have two choices:

1. Include the element
2. Exclude the element

The recursion explores all possible combinations of 3 numbers.

---

## Pseudo-code

```text
function MaxProductRecursive(A, index, count, currentProduct):

    if count == 3:
        return currentProduct

    if index == length(A):
        return -∞

    include =
        MaxProductRecursive(
            A,
            index+1,
            count+1,
            currentProduct × A[index]
        )

    exclude =
        MaxProductRecursive(
            A,
            index+1,
            count,
            currentProduct
        )

    return max(include, exclude)
```

---

## Time & Space Complexity

| Operation | Complexity |
|---|---|
| Recursive Calls | `O(2^n)` |
| Stack Depth | `O(n)` |
| Total Time Complexity | `O(2^n)` |
| Space Complexity | `O(n)` |

---

# Comparison Between Algorithms

| Feature | Sorting | Iterative | Recursive |
|---|---|---|---|
| Time Complexity | `O(n²)` | `O(n)` | `O(2^n)` |
| Space Complexity | `O(1)` | `O(1)` | `O(n)` |
| Array Traversals | Multiple | Single | All combinations |
| Handles Negative Numbers | Yes | Yes | Yes |
| Suitable for Large Input | Moderate | Best | Poor |

---

# Best Approach

### Iterative Approach — Recommended

The iterative solution is the optimal approach because:

- It scans the array only once.
- Uses constant memory.
- Efficient for large arrays.
- Correctly handles:
  - Negative numbers
  - Positive numbers
  - Zeros

---

# Test Cases

| Array | Sorting | Iterative | Recursive | Expected |
|---|---|---|---|---|
| `{2, 3, 4}` | 24 | 24 | 24 | 24 |
| `{6, 7, 8, 10}` | 560 | 560 | 560 | 560 |
| `{-10, -10, 5, 2}` | 500 | 500 | 500 | 500 |
| `{-3, 1, 2, -2, 5, 6}` | 60 | 60 | 60 | 60 |
| `{-5, -4, -3, -2}` | -24 | -24 | -24 | -24 |
| `{0, 0, 0}` | 0 | 0 | 0 | 0 |

---

# Technologies Used

- C++
- STL Vector
- Bubble Sort
- Recursion
- Iterative Algorithms

---

