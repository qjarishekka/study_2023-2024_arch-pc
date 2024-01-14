#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double function(double x) {
    return log((1 + x * x) * tan(x * x));
}

double exactDerivative(double x) {
    return (2 * x * tan(x * x) / (1 + x * x)) + (2 * x * log(1 + x * x) / (cos(x * x) * cos(x * x)));
}

int main() {
    cout << fixed << setprecision(6);
    // Point of interest
    double X = 0.3;

    // Exact derivative
    double exactDerivativeValue = exactDerivative(X);
    cout << "Exact Derivative at X=0.3: " << exactDerivativeValue << endl;

    // DX values
    double DX[] = { 0.00000025, 0.000005, 0.0001, 0.002, 0.04, 0.8 };

    // Output table header
    cout << "\nDX\t\t\tDY\t\t\tDY/DX\t\t\tAbsolute Error\n";

    // Loop through each DX value
    for (int i = 0; i < sizeof(DX) / sizeof(DX[0]); ++i) {
        // Calculate Y(X + DX)
        double Y1 = function(X + DX[i]);

        // Calculate Y(X)
        double Y2 = function(X);

        // Calculate DY
        double DY = Y1 - Y2;

        // Calculate DY/DX ratio
        double ratio = DY / DX[i];

        // Calculate absolute error
        double error = abs(ratio - exactDerivativeValue);

        // Output values in tabular form
        cout << DX[i] << "\t\t" << DY << "\t\t" << ratio << "\t\t" << error << endl;
    }

    return 0;
}