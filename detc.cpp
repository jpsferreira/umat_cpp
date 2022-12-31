#include <iostream>
#include <cmath>

using namespace std;

// Expose the function to C
// Function to calculate the determinant of a 3x3 matrix m
extern "C" double** determinant(double** m) {
    // Calculate the determinant using the formula:
    // |A B C|
    // |D E F| = A(EI - FH) - B(DI - FG) + C(DH - EG)
    // |G H I|
    return m;
    // return m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1])
    //      - m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0])
    //      + m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
}
