# Original array: 3 1 4 4 2 2 5

# After sorting:   1 2 2 3 4 4 5

- **Iteration 1:**
  - `i = 1`, `arr[i] = 2`, `uniqueIndex = 0`, `arr[uniqueIndex] = 1`, `arr[1] != arr[0]` (true)
    - Increment uniqueIndex: `uniqueIndex = 1`
    - Copy `arr[1]` to `arr[1]`: `arr = {1, 2, 2, 3, 4, 4, 5}`
  - **After iteration 1:** Unique elements: 1 2

- **Iteration 2:**
  - `i = 2`, `arr[i] = 2`, `uniqueIndex = 1`, `arr[uniqueIndex] = 2`, `arr[2] == arr[1]` (true)
    - Duplicate found, continue
  - **After iteration 2:** Unique elements: 1 2

- **Iteration 3:**
  - `i = 3`, `arr[i] = 3`, `uniqueIndex = 1`, `arr[uniqueIndex] = 2`, `arr[3] != arr[1]` (true)
    - Increment uniqueIndex: `uniqueIndex = 2`
    - Copy `arr[3]` to `arr[2]`: `arr = {1, 2, 3, 3, 4, 4, 5}`
  - **After iteration 3:** Unique elements: 1 2 3

- **Iteration 4:**
  - `i = 4`, `arr[i] = 4`, `uniqueIndex = 2`, `arr[uniqueIndex] = 3`, `arr[4] != arr[2]` (true)
    - Increment uniqueIndex: `uniqueIndex = 3`
    - Copy `arr[4]` to `arr[3]`: `arr = {1, 2, 3, 4, 4, 4, 5}`
  - **After iteration 4:** Unique elements: 1 2 3 4

- **Iteration 5:**
  - `i = 5`, `arr[i] = 4`, `uniqueIndex = 3`, `arr[uniqueIndex] = 4`, `arr[5] == arr[3]` (true)
    - Duplicate found, continue
  - **After iteration 5:** Unique elements: 1 2 3 4

- **Iteration 6:**
  - `i = 6`, `arr[i] = 5`, `uniqueIndex = 3`, `arr[uniqueIndex] = 4`, `arr[6] != arr[3]` (true)
    - Increment uniqueIndex: `uniqueIndex = 4`
    - Copy `arr[6]` to `arr[4]`: `arr = {1, 2, 3, 4, 5, 4, 5}`
  - **After iteration 6:** Unique elements: 1 2 3 4 5

**Result:** Unique elements: 1 2 3 4 5
