/// @file <leibnitz_pi_converge.cpp>
/// @brief <Part II of Project Pi>
/// @author <kelung@chapman.edu>

#include <iostream>
#include <cmath>
#include <cfloat>
#include <iomanip>

using namespace std;

int main() {
    double pi = 0.0;
    double piOver4 = 0.0;

    for (int n = 2; n <= 1048576; n *= 2) {
        piOver4 = 0.0;
        for (int k = 0; k <= n; k++){
            piOver4 += ((pow(-1.0, k)) / ((2.0 * k) + 1.0));
        }

        pi = piOver4 * 4.0;

        cout << "PI: " << fixed << setprecision(DBL_DIG) << pi << "; n: " << setw(7) << n << endl;
    }

}
