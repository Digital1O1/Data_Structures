Original array :     int Array[] = {1, 2, 3, 4, 5};

newArray = {3, 4, 1, 2, 3}


| Step | i   | rightRotations | Condition (i < rightRotations) | Array Index Accessed | Value Printed | newArray[i] Value | original array value|
|------|-----|----------------|--------------------------------|----------------------|---------------|-------------------| -------------------|
| 1    | 0   | 2              | true    (0 < 2)                           | originalArray [4+0-2] | 3             | 3                 | 1
| 2    | 1   | 2              | true    (1 < 2)                       | originalArray [4+1-2] | 4             | 4                 |2
| 3    | 2   | 2              | false   (2 = 2)                      | originalArray [2-2]   | 1             | 1                 |3
| 4    | 3   | 2              | false   (2 < 3)                       | originalArray [3-2]   | 2             | 2                 |4
| 5    | 4   | 2              | false    (4 < 2)                      | originalArray [4-2]   | 3             | 3                 | 5
