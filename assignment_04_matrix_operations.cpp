// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void readMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(6) << matrix[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(int matrix[10][10], int rows, int cols) {
    int transpose[10][10];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transpose[j][i] = matrix[i][j];
        }
    }

    cout << "Transpose:" << endl;
    printMatrix(transpose, cols, rows);
}

void addMatrices(int a[10][10], int b[10][10], int rows, int cols) {
    int result[10][10];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }

    cout << "Sum Matrix:" << endl;
    printMatrix(result, rows, cols);
}

void multiplyMatrices(int a[10][10], int b[10][10], int rowsA, int colsA, int rowsB, int colsB) {
    int result[10][10] = {0};
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            for (int k = 0; k < colsA; ++k) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    cout << "Product Matrix:" << endl;
    printMatrix(result, rowsA, colsB);
}

int main() {
    int choice;
    cout << "Matrix Operations" << endl;
    cout << "1. Transpose" << endl;
    cout << "2. Add Matrices" << endl;
    cout << "3. Multiply Matrices" << endl;
    cout << "Choose an option: ";
    cin >> choice;

    if (choice == 1) {
        int rows, cols;
        int matrix[10][10];

        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        readMatrix(matrix, rows, cols);
        cout << "Original Matrix:" << endl;
        printMatrix(matrix, rows, cols);
        transposeMatrix(matrix, rows, cols);
    } else if (choice == 2) {
        int rows, cols;
        int a[10][10], b[10][10];

        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        cout << "Matrix A" << endl;
        readMatrix(a, rows, cols);
        cout << "Matrix B" << endl;
        readMatrix(b, rows, cols);

        addMatrices(a, b, rows, cols);
    } else if (choice == 3) {
        int rowsA, colsA, rowsB, colsB;
        int a[10][10], b[10][10];

        cout << "Enter rows for matrix A: ";
        cin >> rowsA;
        cout << "Enter columns for matrix A: ";
        cin >> colsA;
        cout << "Enter rows for matrix B: ";
        cin >> rowsB;
        cout << "Enter columns for matrix B: ";
        cin >> colsB;

        if (colsA != rowsB) {
            cout << "Error: Number of columns in A must equal number of rows in B." << endl;
            return 0;
        }

        cout << "Matrix A" << endl;
        readMatrix(a, rowsA, colsA);
        cout << "Matrix B" << endl;
        readMatrix(b, rowsB, colsB);

        multiplyMatrices(a, b, rowsA, colsA, rowsB, colsB);
    } else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}

