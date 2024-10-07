#include <iostream>
#include<cmath>
using namespace std;



// double limit(double a, double b, double x) {
//     return 0.5 * (b - a) * x + 0.5 * (b + a);
// }
double func(double x) {
//  f(x) = e^-x/(1+x^2)
    double numerator = 1;
    double denominator = 1 + pow(x, 2);
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
    int n = 5; // 5-point Technique
    double gauss_laguerre_nodes[5] = { 0.26356, 1.4134, 3.59643, 7.08581, 12.6408 };
    double gauss_laguerre_weights[5] = { 0.521756, 0.398667, 0.0759424, 0.00361176, 0.00002337 };

    double result = gauss_laguerre_integral(gauss_laguerre_nodes, gauss_laguerre_weights, n);

    cout << "Approximate integral: " << result << endl;

    return 0;
}
