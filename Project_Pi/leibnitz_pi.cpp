/// @file <leibnitz_pi.cpp>
/// @brief <Using the Leibnitz formula to approximate the value of π>
/// @author <kelung@chapman.edu>

#include <iostream>
#include <cmath>
#include <cfloat>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cout << "Please enter a non-negative integer upper limit of summation for the Leibnitz formula for computing pi:" << endl;
    cin >> n;
    double pi;
    double piOver4 = 0.0;
    
    for (int k = 0; k <= n; k++) {
        piOver4 += ((pow(-1, k)) / (2.0 * k + 1.0));
    }
    pi = piOver4 * 4.0;
    
    cout << "PI (approx): " << fixed << setprecision(DBL_DIG) << pi << "; n: " << setw(7) << n << endl;
    cout << "PI (actual): " << "3.141592653589793" << endl;
    cout << "Decimal digits of precision: " << DBL_DIG << endl;
    cout << "Number of base 2 mantissa digits of double precision floating point value: " <<  DBL_MANT_DIG << endl;
    cout << "Next representable number from 3.141592653589793: " << nextafter(3.141592653589793, 3.14) << endl;
    return 0;
}
