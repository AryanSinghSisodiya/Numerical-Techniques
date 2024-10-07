#include <iostream>
#include<cmath>
using namespace std;



// double limit(double a, double b, double x) {
//     return 0.5 * (b - a) * x + 0.5 * (b + a);
// }

double func(double x) {
//  f(x) = e^-x/(1+x^2)
    double numerator = exp(x);
    double denominator = 2+ 2*x + pow(x, 2);
    return numerator / denominator;
}
double gauss_laguerre_integral(double nodes[], double weights[], int n) {
    double integral = 0.0;
    for (int i = 0; i < n; i++) {
        integral += weights[i] * func(nodes[i]);
    }
    return integral; 
}



int main() {
    int n = 3; // 3-point Technique
    double gauss_laguerre_nodes[3] = { 0.415775, 2.29428, 6.28995 };
    double gauss_laguerre_weights[3] = { 0.711093, 0.278518,0.0103893};

    double result = gauss_laguerre_integral(gauss_laguerre_nodes, gauss_laguerre_weights, n);

    cout << "Approximate integral: " << result << endl;

    return 0;
}
