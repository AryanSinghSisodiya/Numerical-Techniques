#include <iostream>
using namespace std;

const double gauss_legendre_nodes[5] = { -0.906179845938664, -0.538469310105683, 0.0, 0.538469310105683, 0.906179845938664 };
const double gauss_legendre_weights[5] = { 0.236926885056189, 0.478628670499366, 0.568888888888889, 0.478628670499366, 0.236926885056189 };

// double limit(double a, double b, double x) {
//     return 0.5 * (b - a) * x + 0.5 * (b + a);
// }

double gauss_legendre_integral(const double* nodes, const double* weights, int n, double (*func)(double)) {
    double integral = 0.0;
    for (int i = 0; i < n; i++) {
        integral += weights[i] * func(nodes[i]);
    }
    return  integral; 
}

double func(double x) {
    return 1.0 / (3.0 + x);
}

int main() {
    int n = 5; // 5-point Technique

    double result = gauss_legendre_integral(gauss_legendre_nodes, gauss_legendre_weights, n, func);

    cout << "Approximate integral: " << result << endl;

    return 0;
}
