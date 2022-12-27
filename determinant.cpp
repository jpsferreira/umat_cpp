#include <iostream>
#include <cmath>

using namespace std;

// Expose the function to C
extern "C" {
    double determinant(double** matrix);
}

// Function to calculate the determinant of a 3x3 matrix
double determinant(double** matrix) {
    // Calculate the determinant using the formula:
    // |A B C|
    // |D E F| = A(EI - FH) - B(DI - FG) + C(DH - EG)
    // |G H I|
    return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1])
         - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])
         + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
}
