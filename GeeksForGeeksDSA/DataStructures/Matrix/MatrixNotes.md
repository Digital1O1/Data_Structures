# [Matrix Data Structure](https://www.geeksforgeeks.org/matrix/)

## What is a Matrix?

- A **2D array** arranged in rows and columns.
- Commonly used to represent mathematical matrices.
- Allows for efficient storage and manipulation of data in a structured format.
- The intersection of a **row** and **column** is called a **cell**.
- Typically used when data needs to be stored in a `table` or `grid` format.
- Each element in a matrix is identified by its **row** and **column indices**.

## Components of Matrix Data Structure

### Size
- Defined by the number of **rows** and **columns**.

### Element
- Each entry in a matrix is called an **element** and is identified by its row and column indices.

### Operations
Matrices support common mathematical operations such as:
- **Scalar multiplication**
- **Addition**
- **Subtraction**
- **Matrix multiplication**

---

## Determinant

- A **scalar number** used to solve systems of linear equations and perform other linear algebraic operations.

### Properties of the Determinant:
1. **Square Matrix**: Determinants are defined only for square matrices (e.g., 2x2, 3x3, etc.).
2. **Non-invertibility**: If a matrix's determinant is **zero**, 
      - It is **singular** 
      - And has **no inverse**.
3. **Geometric Interpretation**: 
   - For a 2x2 matrix, the absolute value of the determinant represents the **area of a parallelogram** formed by its column vectors.
   - For a 3x3 matrix, it represents the **volume of the parallelepiped** formed by its column vectors.

# Calculating the Inverse of a Matrix

## The Inverse of a Matrix A

- A matrix \( A \) is said to be invertible if it has an inverse, denoted as \( A^{-1} \).
- The inverse of a matrix \( A \) is a matrix that, when multiplied by \( A \), results in the identity matrix \( I \).

## Conditions for Invertibility

- For a square matrix (same number of rows and columns), the **determinant** must be **non-zero**.
- Not all matrices have an inverse; 
  - a matrix must meet these two conditions to be invertible.

# Steps to Calculate the Inverse of a Matrix

### Step 1: Verify the Matrix is Square

- Check if the matrix \( A \) has the `same number` of rows and columns.
- Example: A \( 3 \times 3 \) matrix is square, but a \( 3 \times 2 \) matrix is not.

### Step 2: Check the Determinant

- Compute the determinant of \( A \) using `cofactor expansion` or other `determinant rules`.
- If \( \text{det}(A) = 0 \), the matrix is `singular` and `does NOT have an inverse`.


### Step 3 : Calculate the Cofactor Matrix

#### Steps to Calculate the Cofactor Matrix

##### 1. Find the Minor of Each Element:
The minor of an element \( a_{ij} \) is the determinant of the submatrix obtained by removing the \( i \)-th row and \( j \)-th column of the matrix \( A \).

##### 2. Apply the Cofactor Formula:
The cofactor \( C_{ij} \) is calculated by multiplying the minor \( M_{ij} \) by \( (-1)^{i+j} \), where \( (-1)^{i+j} \) accounts for the alternating signs based on the position of the element.

#### 3. Construct the Cofactor Matrix:
Replace each element \( a_{ij} \) in the matrix \( A \) with its corresponding cofactor \( C_{ij} \).

---

### Example: Cofactor Matrix for Matrix \( A \)

Let’s compute the cofactor matrix for the matrix \( A \):

\[
A = \begin{bmatrix}
2 & 4 & 3 \\
1 & 5 & 7 \\
8 & 9 & 6
\end{bmatrix}
\]

#### Step 1: Compute the Minors
We will calculate the minors for each element in the matrix \( A \).

##### 1.1 Compute the Minor for \( a_{11} = 2 \)

\[
A = \begin{bmatrix}
2 & 4 & 3 \\
1 & 5 & 7 \\
8 & 9 & 6
\end{bmatrix}
\]


To compute the minor of \( a_{11} \), we remove the `1st row` and `1st column` from \( A \). The remaining submatrix is:

\[
A_{11} = \begin{bmatrix} 
5 & 7 \\ 
9 & 6
\end{bmatrix}
\]

Now, compute the `determinant` of this 2x2 submatrix:

\[
A = \begin{bmatrix}
2 & 4 & 3 \\
1 & 5 & 7 \\
8 & 9 & 6
\end{bmatrix}
\]


\[
\text{det}(A_{11}) = (5)(6) - (7)(9) = 30 - 63 = -33
\]

So, the minor \( M_{11} = -33 \).

##### 1.2 Compute the Minor for \( a_{12} = 4 \)

\[
A = \begin{bmatrix}
2 & 4 & 3 \\
1 & 5 & 7 \\
8 & 9 & 6
\end{bmatrix}
\]


For \( a_{12} \), we remove the `1st row` and `2nd column` from \( A \). The remaining submatrix is:

\[
A_{12} = \begin{bmatrix}
1 & 7 \\
8 & 6
\end{bmatrix}
\]

Now, compute the determinant of this 2x2 submatrix:

\[
\text{det}(A_{12}) = (1)(6) - (7)(8) = 6 - 56 = -50
\]

So, the minor \( M_{12} = -50 \).

##### 1.3 Compute the Minor for \( a_{13} = 3 \)

\[
A = \begin{bmatrix}
2 & 4 & 3 \\
1 & 5 & 7 \\
8 & 9 & 6
\end{bmatrix}
\]


For \( a_{13} \), we remove the `1st row` and `3rd column` from \( A \). The remaining submatrix is:

\[
A_{13} = \begin{bmatrix}
1 & 5 \\
8 & 9
\end{bmatrix}
\]

Now, compute the determinant of this 2x2 submatrix:

\[
\text{det}(A_{13}) = (1)(9) - (5)(8) = 9 - 40 = -31
\]

So, the minor \( M_{13} = -31 \).

##### 1.4 Repeat for Remaining Elements
Now, we repeat the process for all the remaining elements of the matrix. Below are the minors for each element:

- \( M_{21} = -3 \)
- \( M_{22} = -12 \)
- \( M_{23} = -14 \)
- \( M_{31} = 13 \)
- \( M_{32} = 11 \)
- \( M_{33} = 6 \)

#### TL;DR when calculating minors in matricies 
- Ignore the row/column for the value you're calculating 
- Then calculate the determinate 


---

#### Step 2: Apply the Cofactor Formula

Now, we use the cofactor formula:

\[
C_{ij} = (-1)^{i+j} \cdot M_{ij}
\]

Where \( M_{ij} \) is the minor of \( a_{ij} \) and \( (-1)^{i+j} \) is the sign factor.

##### Row 1 Cofactors:
- \( C_{11} = (-1)^{1+1} \cdot (-33) = -33 \)
- \( C_{12} = (-1)^{1+2} \cdot (-50) = +50 \)
- \( C_{13} = (-1)^{1+3} \cdot (-31) = -31 \)

##### Row 2 Cofactors:
- \( C_{21} = (-1)^{2+1} \cdot (-3) = +3 \)
- \( C_{22} = (-1)^{2+2} \cdot (-12) = -12 \)
- \( C_{23} = (-1)^{2+3} \cdot (-14) = +14 \)

##### Row 3 Cofactors:
- \( C_{31} = (-1)^{3+1} \cdot (13) = +13 \)
- \( C_{32} = (-1)^{3+2} \cdot (11) = -11 \)
- \( C_{33} = (-1)^{3+3} \cdot (6) = +6 \)

---

#### Step 3: Construct the Cofactor Matrix

The cofactor matrix is:

\[
\text{Cofactor Matrix} = \begin{bmatrix}
-33 & 50 & -31 \\
3 & -12 & 14 \\
13 & -11 & 6
\end{bmatrix}
\]

This is the cofactor matrix for \( A \).

---

### Step 4: Construct the Adjugate Matrix

- Just tneed to trasnpose the cofactor matrix we have earlier 
  - Swap rows and columns 

#### From this

\[
\begin{bmatrix}
-33 & 50 & -31 \\
3 & -12 & 14 \\
13 & -11 & 6
\end{bmatrix}
\]


#### To this 



\[
\text{Adjugate Matrix} = \begin{bmatrix}
-33 & 3 & 13 \\
50 & -12 & -11 \\
-31 & 14 & 6
\end{bmatrix}
\]



### Step 5: Divide by the Determinant

Given a matrix \( \mathbf{A} \), we can compute the inverse \( \mathbf{A}^{-1} \) (if it exists) using the formula:

\[
\mathbf{A}^{-1} = \frac{1}{\text{det}(\mathbf{A})} \cdot \text{Adj}(\mathbf{A}),
\]

where:

- \( \text{det}(\mathbf{A}) \) is the determinant of the matrix \( \mathbf{A} \),
- \( \text{Adj}(\mathbf{A}) \) is the adjugate matrix (or adjoint matrix).

### Conditions for Division by the Determinant

For a matrix to have an inverse, the determinant must be non-zero. If \( \text{det}(\mathbf{A}) = 0 \), the matrix is singular, and it does not have an inverse.

## Example

Let’s say we have the matrix \( \mathbf{A} \) and its adjugate matrix \( \text{Adj}(\mathbf{A}) \), and we want to compute the inverse.

### Given:
\[
\mathbf{A} = \begin{bmatrix}
2 & 4 & 3 \\
1 & 5 & 7 \\
8 & 9 & 6
\end{bmatrix}
\]
And the adjugate matrix (which we've calculated in previous examples):

\[
\text{Adj}(\mathbf{A}) = \begin{bmatrix}
-33 & 50 & -31 \\
3 & -12 & 14 \\
13 & -11 & 6
\end{bmatrix}
\]

We previously found that:
\[
\text{det}(\mathbf{A}) = -3
\]

### Step 1: Divide by the Determinant

Now that we have the adjugate matrix \( \text{Adj}(\mathbf{A}) \) and the determinant \( \text{det}(\mathbf{A}) = -3 \), we can compute the inverse using the formula:

\[
\mathbf{A}^{-1} = \frac{1}{\text{det}(\mathbf{A})} \cdot \text{Adj}(\mathbf{A})
\]

This means we multiply the adjugate matrix by the scalar \( \frac{1}{\text{det}(\mathbf{A})} \). In this case, \( \frac{1}{\text{det}(\mathbf{A})} = \frac{1}{-3} \).

Multiply the Adjugate Matrix by \( \frac{1}{\text{det}(\mathbf{A})} \):

\[
\mathbf{A}^{-1} = \frac{1}{-3} \cdot \begin{bmatrix}
-33 & 50 & -31 \\
3 & -12 & 14 \\
13 & -11 & 6
\end{bmatrix}
\]

Now, multiply each element of the adjugate matrix by \( \frac{1}{-3} \):

\[
\mathbf{A}^{-1} = \begin{bmatrix}
\frac{11}{3} & -\frac{50}{3} & \frac{31}{3} \\
-1 & 4 & -\frac{14}{3} \\
-\frac{13}{3} & \frac{11}{3} & -2
\end{bmatrix}
\]

### Step 2: The Inverse Matrix

After multiplying by \( \frac{1}{\text{det}(\mathbf{A})} \), we have the inverse matrix \( \mathbf{A}^{-1} \):

\[
\mathbf{A}^{-1} = \begin{bmatrix}
\frac{11}{3} & -\frac{50}{3} & \frac{31}{3} \\
-1 & 4 & -\frac{14}{3} \\
-\frac{13}{3} & \frac{11}{3} & -2
\end{bmatrix}
\]


## Another way to calculate the determinate for a 3x3 matrix

#### 3x3 Matrix : using the `Sarrus Rule`

This method is a simple and efficient way to calculate the determinant of a
3x3 matrix. It involves multiplying the elements in each row and column in
a specific pattern, then adding up the results.


\[
A = \begin{pmatrix} 1 & 2 & 3 \\ 4 & 5 & 6 \\ 7 & 8 & 9 \end{pmatrix}
\]


**Step 1: Multiply elements in each row:**

* Row 1: `a11*a22*a33 + a12*a23*a31 = 1*5*9 + 2*6*7`
* Row 2: `a21*a13*a32 - a22*a12*a31 = 4*3*8 - 5*2*7`
* Row 3: `a31*a11*a23 - a32*a21*a13 + a33*a11*a22 - a33*a21*a12 = 7*1*6 -
8*4*3 + 9*1*5 - 9*4*2`

**Step 2: Simplify the expressions:**

* Row 1: `45 + 84 = 129`
* Row 2: `96 - 140 = -44`
* Row 3: `42 - 192 + 45 - 72 = -77`

**Step 3: Add and subtract the results:**

`129 - (-44) - (-77) = 129 + 44 + 77 = 250`

Therefore, the determinant of matrix A is `250`.

#### **Shortcut for Sarrus Rule Pattern** -->

##### Given a 3x3 matrix A 

\[
A = \begin{pmatrix} a & b & c \\ d & e & f \\ g & h & i
\end{pmatrix}
\]


The determinant of A can be calculated using Sarrus' Rule as follows:

#### Formula to find 3x3 determinate 

```markdown
det(A) = a(ei - fh) - b(di - fg) + c(dh - eg)
```

Where ei, fh, di, fg, dh, and eg are the products of the corresponding elements in the matrix.



---

## Inverse

If a square matrix has an `inverse`, it can be used to solve systems of linear equations and perform other linear algebraic operations.

### How to Determine if a Square Matrix Has an Inverse

A square matrix has an inverse if and only if its **determinant** is **non-zero**. 

If the determinant is zero, the matrix is **singular** and does **<u>not have an inverse</u>**.

#### Steps to Check if a Matrix Has an Inverse:
1. **Compute the Determinant**:
   - If \(\text{det}(A) \neq 0\), the matrix is **invertible** (has an inverse).
   - If \(\text{det}(A) = 0\), the matrix is **singular** (does not have an inverse).

#### Example for a 2x2 Matrix:
Given a 2x2 matrix \(A\):

\[
A = \begin{pmatrix} a & b \\ c & d \end{pmatrix}
\]

The determinant of \(A\) is:

\[
\text{det}(A) = ad - bc
\]

- If \(\text{det}(A) \neq 0\), \(A\) has an inverse.
- If \(\text{det}(A) = 0\), \(A\) does not have an inverse.

#### Example:
Let \(A = \begin{pmatrix} 2 & 3 \\ 4 & 6 \end{pmatrix}\).

\[
\text{det}(A) = (2)(6) - (3)(4) = 12 - 12 = 0
\]

Since \(\text{det}(A) = 0\), the matrix does **NOT** have an inverse.

#### Example for a 3x3 Matrix:
Given a 3x3 matrix \(A\):

\[
A = \begin{pmatrix} a & b & c \\ d & e & f \\ g & h & i \end{pmatrix}
\]

The determinant is calculated as:

\[
\text{det}(A) = a(e i - f h) - b(d i - f g) + c(d h - e g)
\]

- If \(\text{det}(A) \neq 0\), the matrix is invertible.
- If \(\text{det}(A) = 0\), the matrix is singular and does not have an inverse.

### Don't forget about Serraus Method to find determinant for a 3x3 matrix

\[
A = \begin{pmatrix} a & b & c \\ d & e & f \\ g & h & i
\end{pmatrix}
\]

#### Formula

```markdown
det(A) = a(ei - fh) - b(di - fg) + c(dh - eg)
```

Where ei, fh, di, fg, dh, and eg are the products of the corresponding elements in the matrix.



### Summary:
- **Non-zero determinant** (\(\text{det}(A) \neq 0\)): The matrix has an `inverse`.
- **Zero determinant** (\(\text{det}(A) = 0\)): The matrix `does not have an inverse`.

---

## Transpose

A matrix's **transpose** is created by flipping it along its main diagonal, switching its rows and columns.

### Example:
Given the matrix \(A\):

\[
A = \begin{pmatrix} 
1 & 2 & 3 \\ 
4 & 5 & 6
\end{pmatrix}
\]

The transpose of \(A\), denoted as \(A^T\), is:

\[
A^T = \begin{pmatrix} 
1 & 4 \\ 
2 & 5 \\ 
3 & 6 
\end{pmatrix}
\]

### Explanation:
- The first row of \(A\) (1, 2, 3) becomes the first column of \(A^T\).
- The second row of \(A\) (4, 5, 6) becomes the second column of \(A^T\).
- The original matrix \(A\) (with dimensions \(2 \times 3\)) changes to \(3 \times 2\) in the transpose.

---

## Rank

### What is it?
- Max number of **linearly independent rows or columns**
- Helps in understanding the matrix's dimensionality 
- Used to solve systems of linear equations

### Steps to Determine the Rank of a Matrix:

1. **Convert the Matrix to Row Echelon Form (REF)** or **Reduced Row Echelon Form (RREF)**:
   - Use **Gaussian elimination** or **Gauss-Jordan elimination** to simplify the matrix.
   - The goal is to get as many leading 1's (pivot positions) as possible in the upper-left portion of the matrix.
   
2. **Count the Number of Non-zero Rows**:
   - After converting the matrix into REF or RREF, `count` the number of rows that contain `at least one non-zero element`.
   - This count represents the **rank** of the matrix.

### Example for a 3x3 Matrix:
Given the matrix \(A\):

\[
A = \begin{pmatrix} 
1 & 2 & 3 \\ 
4 & 5 & 6 \\ 
7 & 8 & 9 
\end{pmatrix}
\]

1. **Apply Gaussian Elimination** to transform \(A\) into Row Echelon Form:

\[
A = \begin{pmatrix} 
1 & 2 & 3 \\ 
0 & -3 & -6 \\ 
0 & 0 & 0 
\end{pmatrix}
\]

2. **Count the Non-zero Rows**:
   - There are **two** non-zero rows: \( \begin{pmatrix} 1 & 2 & 3 \end{pmatrix} \) and \( \begin{pmatrix} 0 & -3 & -6 \end{pmatrix} \).
   
   Therefore, the **rank of matrix \(A\)** is 2.

### Example for a 2x2 Matrix:
Given the matrix \(B\):

\[
B = \begin{pmatrix} 
1 & 2 \\ 
2 & 4 
\end{pmatrix}
\]

1. **Apply Gaussian Elimination**:

\[
B = \begin{pmatrix} 
1 & 2 \\ 
0 & 0 
\end{pmatrix}
\]

2. **Count the Non-zero Rows**:
   - There is only **one** non-zero row, so the rank of \(B\) is `1`.

### Summary:
- Convert the matrix to **Row Echelon Form** or **Reduced Row Echelon Form**.
- Count the number of non-zero rows in the transformed matrix.
- The number of non-zero rows equals the **rank** of the matrix.

---
<br>

# [Matrix or Grid or 2D Array – Complete Tutorial](https://www.geeksforgeeks.org/introduction-to-matrix-or-grid-data-structure-and-algorithms-tutorial/)

## Reminder, first value always top left element

## Declaration/initializing of a Matrix D.S

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Defining number of rows and columns in matrix
    int rows = 3, cols = 3;

    // Vector of vectors declaration
    vector<vector<int>> arr(rows, vector<int>(cols));
 
    // Initializing a 2-D vector with values
    vector<vector<int>> arr2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};


    return 0;
}
```

## Operations on Matricies
### Most common operations
- Access elements of Matrix
- Traversal of a Matrix
- Searching in a Matrix
- Sorting a Matrix

### Access elements of Matrix Data Structure
- Similar to `1D arrays`
  - Matricies can be accessed by `using their indices` to access the individual elements
- Each cell has `two indicies`
  - Row number
  - Column number
  - Can use `[i] [j]` to access the element 
    - At the `ith` row and the `jth` column of the matrix
      ```cpp
      #include <iostream>
      #include <vector>
      using namespace std;

      int main()
      {
         // Initializing a 2-D vector with values
         vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

         // Accessing elements of 2-D vector
         cout << "First element of first row: " << arr[0][0] << "\n";
         cout << "Third element of second row: " << arr[1][2] << "\n";
         cout << "Second element of third row: " << arr[2][1] << "\n";

         return 0;
      }
      ```

### Traversing a matrix 
- Use two for loops

   ```cpp
   #include <bits/stdc++.h>
   using namespace std;

   int main()
   {
      // Initializing a 2-D vector with values
      vector<vector<int>> arr = { { 1, 2, 3, 4 },
                                 { 5, 6, 7, 8 },
                                 { 9, 10, 11, 12 } };

      // Traversing over all the rows
      for (int i = 0; i < arr.size(); i++) {
         
         // Traversing over all the columns of each row
         for (int j = 0; j < arr[i].size(); j++) {
               cout << arr[i][j] << " ";
         }
         cout << endl;
      }

      return 0;
   }
   /*
   Output
   1 2 3 4 
   5 6 7 8 
   9 10 11 12 
   */
   ```
### Searching a matrix
- By traversing all the elements in a matrix
  ```cpp
  #include <bits/stdc++.h>
  using namespace std;

   bool searchInMatrix(vector<vector<int> >& arr, int x)
   {
      int m = arr.size(), n = arr[0].size();

      for (int i = 0; i < m; i++) {
         for (int j = 0; j < n; j++) {
               if (arr[i][j] == x)
                  return true;
         }
      }
      return false;
   }

   // Driver program to test above
   int main()
   {
      int x = 8;
      vector<vector<int> > arr
         = { { 0, 6, 8, 9, 11 },
               { 20, 22, 28, 29, 31 },
               { 36, 38, 50, 61, 63 },
               { 64, 66, 100, 122, 128 } };

      if (searchInMatrix(arr, x))
         cout << "YES" << endl;
      else
         cout << "NO" << endl;

      return 0;
   }

  ```

### Sorting a matrix
#### Two ways
- Row-wise
##### Using `Arrays.sort()`
   ```cpp
   // C++ code to sort 2D 
   // matrix row-wise
   #include <bits/stdc++.h>
   using namespace std;
   #define M 4
   #define N 4

   int sortRowWise(int m[M][N])
   {
      // One by one sort 
      // individual rows.
      for (int i = 0; i < M; i++)
         sort(m[i], m[i] + N);

      // Printing the sorted matrix
      for (int i = 0; i < M; i++) 
      {
         for (int j = 0; j < N; j++)
         cout << (m[i][j]) << " ";
         cout << endl;
      }
   }

   // Driver code
   int main()
   {
      int m[M][N] = {{9, 8, 7, 1},
                  {7, 3, 0, 2},
                  {9, 5, 3, 2},
                  {6, 3, 1, 2}};
      sortRowWise(m);
   }

   // This code is contributed by gauravrajput1

   ```


- Column-wise
  - First step : traverse the matrix
  - Second step : calculate the transpose
  - Third step : Store the transpose of `mat[][]` in a 2D vector `tr[][]`
  - Fourth step : Traverse the rows of `tr[][]`
  - Sixth step : Sort each row of the matrix using the sort function
  - Seventh step : Store the transpose of `tr[][]` in `mat[][]`
  - Eighth step : Print the matrix `mat[][]`

```cpp
// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to find the transpose
// of the matrix mat[]
vector<vector<int> > transpose(
	vector<vector<int> > mat,
	int row, int col)
{

	// Stores the transpose
	// of matrix mat[][]
	vector<vector<int> > tr(
		col, vector<int>(row));

	// Traverse each row of the matrix
	for (int i = 0; i < row; i++) {

		// Traverse each column of the matrix
		for (int j = 0; j < col; j++) {

			// Transpose matrix elements
			tr[j][i] = mat[i][j];
		}
	}

	return tr;
}

// Function to sort the given
// matrix in row wise manner
void RowWiseSort(vector<vector<int> >& B)
{
	// Traverse the row
	for (int i = 0; i < (int)B.size(); i++) {

		// Row - Wise Sorting
		sort(B[i].begin(), B[i].end());
	}
}

// Function to print the matrix
// in column wise sorted manner
void sortCol(vector<vector<int> > mat,
			int N, int M)
{
	// Function call to find transpose
	// of the matrix mat[][]
	vector<vector<int> > B
		= transpose(mat, N, M);

	// Sorting the matrix row-wise
	RowWiseSort(B);

	// Calculate transpose of B[][]
	mat = transpose(B, M, N);

	// Print the matrix mat[][]
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			cout << mat[i][j] << " ";
		}
		cout << '\n';
	}
}

// Driver Code
int main()
{
	// Input
	vector<vector<int> > mat = { { 1, 6, 10 },
								{ 8, 5, 9 },
								{ 9, 4, 15 },
								{ 7, 3, 60 } };

	int N = mat.size();
	int M = mat[0].size();

	// Function call to print the matrix
	// in column wise sorted manner
	sortCol(mat, N, M);

	return 0;
}

```

**Advantages when using Matricies**
=========================

| **Advantage** | **Description** |
| --- | --- |
| 2D Visualization | Enables visualization of data in a 2D format, making it easier to understand complex relationships between elements. |
| Efficient Storage | Stores multiple elements of the same type using the same name. |
| Random Access | Enables access to items at random positions within the matrix. |
| Fixed Size Data | Any form of data with a fixed size can be stored in a matrix. |
| Easy Implementation | Matrix operations are relatively simple to implement, making it a popular choice for many applications. |

<br>

**Disadvantage when using Matricies**
-----------------

| **Disadvantage** | **Description** |
| --- | --- |
| Space Inefficiency | Can lead to space inefficiency when storing very few elements in the matrix, such as sparse graphs. |
| Fixed Matrix Size | The size of the matrix should be determined beforehand, which can limit its flexibility. |
| Costly Operations | Insertion and deletion operations can be costly if shifting occurs within the matrix. |
| Resizing Challenges | Resizing a matrix can be time-consuming and may require significant memory reallocation.

---

# Basic Operations on Matrix Data Structure

## [Traverse a given Matrix using Recursion](https://www.geeksforgeeks.org/traverse-a-given-matrix-using-recursion/)
- Given the matrix `arr` of size `N x M` the task is to traverse the matrix using `recusion`
```markdown
Input: arr[][] = {{1, 2, 3}, 
                  {4, 5, 6},
                  {7, 8, 9}} 
Output: 1, 2, 3, 4, 5, 6, 7, 8, 9

Input: M[][] = {{11, 12, 13}, 
                  {14, 15, 16}, 
                  {17, 18, 19}}
Output: 11, 12, 13, 14, 15, 16, 17, 18, 19
```

## Approach: 
- Check If the current position is in the bottom-right corner of the matrix
   - Print the value at that position
   - End the recursion
- Print the value at the current position
- Check If the end of the current row has not been reached
   - Move right
- Check If the end of the current column has been reached
   - Move down to the next row

## Solution
```cpp

#include <iostream>

using namespace std;

// Define the dimensions of the matrix
const int setRow = 3;
const int setColumn = 3;

// Recursive function to traverse the matrix
// When passing a multi-dimension array, the compiler needs to know the number of columns so it can correctly compute the memory offset 

void traverse(int arr[][setColumn], int row_, int column_)
{
	// If the current position is the bottom-right corner of
	// the matrix use recursion to call traverse() again
   // if( 0 == 3 - 1 && 0 == 3 - 1) --> if(0 == 2 && 0 == 2)
	if (row_ == setRow - 1 && column_ == setColumn - 1) 
   {
		// Print the value at that position
		cout << arr[row_][column_] << endl;
		// End the recursion
		return;
	}

	// Print the value at the current position
	cout << arr[row_][column_] << ", ";

	// If the end of the current setRow has not been reached
	if (column_ < setColumn - 1) 
   {
		// Move right
		traverse(arr, row_, column_ + 1);
	}
	// If the end of the current column has been reached
	else if (row_ < setRow - 1) 
   {
		// Move down to the next row
		traverse(arr, row_ + 1, 0);
	}
}

int main()
{
	// Define the matrix
	int arr[setRow][setColumn]
		= { { 1, 2, 3 }, 
          { 4, 5, 6 }, 
          { 7, 8, 9 } };

	// Start the traversal from the top-left corner of the
	// matrix
	traverse(arr, 0, 0);

	return 0;
}
```

---

# [Rotate Matrix Clockwise By 1](https://www.geeksforgeeks.org/rotate-matrix-elements/)

## When given a square matrix rotate it's elements clockwise by one step

```markdown
Input 
1    2    3
4    5    6 
7    8    9
Output: 
4    1    2
7    5    3 
8    9    6


Input: 
1    2    3    4 
5    6    7    8 
9    10   11   12
13   14   15   16 
Output: 
5    1    2    3 
9    10   6    4 
13   11   7    8 
14   15   16   12
```

## Main idea

### Use nested loops 
- To move elements in four directions 
  - One step at a time for each layer 
  - Starting with `outermost` layer
  - This stimulates the clockwise rotation by rotating each 'ring' or layer of the matrix
### Steps
1. First move the elements of the outermost layer.
a) Move the top row elements one position ahead (except the last element)
b) Move the rightmost column elements one position down (except the last element)
c) Move the bottom row elements one position left (Except the leftmost element)
d) Move the first column elements one position up (Except the top elements)

1. Repeat the same process for inner layers.

### Example
```cpp
#include <bits/stdc++.h>
using namespace std;

// Function to rotate a matrix represented by a vector of vectors
void rotateMatrix(vector<vector<int>>& mat) {
  
    int m = mat.size();
    int n = mat[0].size();
  
    int row = 0, col = 0;
    int prev, curr;

    // Rotate the matrix in layers
    while (row < m && col < n) {
        if (row + 1 == m || col + 1 == n)
            break;

        // Store the first element of the next row
        prev = mat[row + 1][col];

        // Move elements of the first row
        for (int i = col; i < n; i++) {
            curr = mat[row][i];
            mat[row][i] = prev;
            prev = curr;
        }
        row++;

        // Move elements of the last column
        for (int i = row; i < m; i++) {
            curr = mat[i][n - 1];
            mat[i][n - 1] = prev;
            prev = curr;
        }
        n--;

        // Move elements of the last row
        if (row < m) {
            for (int i = n - 1; i >= col; i--) {
                curr = mat[m - 1][i];
                mat[m - 1][i] = prev;
                prev = curr;
            }
        }
        m--;

        // Move elements of the first column
        if (col < n) {
            for (int i = m - 1; i >= row; i--) {
                curr = mat[i][col];
                mat[i][col] = prev;
                prev = curr;
            }
        }
        col++;
    }
}

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    rotateMatrix(mat);

    // Print the rotated matrix
    for (auto& r : mat) {
        for (int val : r)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}

```