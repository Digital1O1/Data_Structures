```markdown
       Col 1  Col 2  Col 3
Row 1      1      2      3
Row 2      4      5      6
Row 3      7      8      9
```

## Matrix Before Rotation:
Here's your initial 3x3 matrix:

```markdown
1 2 3
4 5 6
7 8 9
```


## Swap Logic:
You're rotating the matrix by 180 degrees. Each element at position `(i, j)` is swapped with its opposite element at position `(num_rows - i - 1, num_columns - j - 1)`.

Opposite elements are swapped between the current row and the last row, and between the current column and the last column.

## Nested Loops Breakdown:
Here’s a step-by-step explanation with each swap:

- **Outer Loop (currentRow):** The first loop iterates through the rows.
- **Inner Loop (currentColumn):** The second loop iterates through the columns.

For each element, you're swapping it with its opposite, and then printing the matrix to see the progress.

## Chart: Swap Process

| Step | currentRow | currentColumn | Position 1 (i, j) | Position 2 (num_rows - currentRow - 1, num_columns - currentColumn - 1) | Swap Values | Matrix After Swap |
|------|------------|---------------|-------------------|----------------------------------------------------|--------------|------------------|
| 1    | 0          | 0             | (0, 0)            | (2, 2)                                            | 1 ↔ 9        | 9 2 3 <br> 4 5 6 <br> 7 8 1 |
| 2    | 0          | 1             | (0, 1)            | (2, 1)                                            | 2 ↔ 8        | 9 8 3 <br> 4 5 6 <br> 7 2 1 |
| 3    | 0          | 2             | (0, 2)            | (2, 0)                                            | 3 ↔ 7        | 9 8 7 <br> 4 5 6 <br> 3 2 1 |
| 4    | 1          | 0             | (1, 0)            | (1, 2)                                            | 4 ↔ 6        | 9 8 7 <br> 6 5 4 <br> 3 2 1 |
| 5    | 1          | 1             | (1, 1)            | (1, 1) (Center stays the same)                    | 5 ↔ 5        | 9 8 7 <br> 6 5 4 <br> 3 2 1 |

## What's Happening:

- **Step 1:** The element at (0,0) (which is 1) is swapped with the element at (2,2) (which is 9).
- **Step 2:** The element at (0,1) (which is 2) is swapped with the element at (2,1) (which is 8).
- **Step 3:** The element at (0,2) (which is 3) is swapped with the element at (2,0) (which is 7).
- **Step 4:** The element at (1,0) (which is 4) is swapped with the element at (1,2) (which is 6).
- **Step 5:** The center element (1,1) stays the same because it doesn’t need to be swapped in a 180-degree rotation (it maps to itself).

## Final Matrix:
After completing the swaps, the matrix is:

```markdown
9 8 7
6 5 4
3 2 1
```


## Key Observations:
- The outer loop iterates through rows (`currentRow`), and the inner loop iterates through columns (`currentColumn`).
- Each element is swapped with its "opposite" element using the formula `arr[num_rows - i - 1][num_columns - j - 1]`.
- The center element remains unchanged in matrices with odd dimensions (like 3x3).
