/*Problem: Given a positive number 𝑥, use binary search to compute its
square root up to a certain precision.

Example:

Input: 𝑥=25

Output: Square Root=5*/

#include <iostream>
#include <iomanip>
using namespace std;

double findSquareRoot(double x, double precision) {
    double low = 0, high = x, mid;
    if (x < 1) high = 1;

    while (high - low > precision) {
        mid = (low + high) / 2;
        if (mid * mid > x) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return (low + high) / 2;
}

int main() {
    double x = 25;
    double precision = 1e-6;

    double result = findSquareRoot(x, precision);

    cout << fixed << setprecision(6) << "Square Root = " << result << endl;

    return 0;
}
