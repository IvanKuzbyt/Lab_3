#include "Methods.h"
#include <cmath>
#include <iostream>

using namespace std;

void Equation_class::setVolumes(double vol_a, double vol_b) {
    a = vol_a;
    b = vol_b;
}

void Equation_class::setStart(double start_x) {
    x0 = start_x;
}

void Equation_class::setTolerance(double vol_eps) {
    eps = vol_eps;
}

double Equation_class::f(double x) {
    return cos(x) - exp(-x * x / 2.0) + x - 1.0;
}

double Equation_class::df(double x) {
    double h = 1e-6;
    return (f(x + h) - f(x)) / h;
}

double Equation_class::solveDyhotomia() {
    double local_a = a;
    double local_b = b;
    while (fabs(local_b - local_a) > eps) {
        double c = (local_a + local_b) / 2.0;
        if (f(local_a) * f(c) < 0)
            local_b = c;
        else
            local_a = c;
    }
    return (local_a + local_b) / 2.0;
}

double Equation_class::solveDyhotomia(double vol_a, double vol_b, double vol_eps) {
    setVolumes(vol_a, vol_b);
    setTolerance(vol_eps);
    return solveDyhotomia();
}

double Equation_class::solveNewton() {
    double x = x0;
    int iter = 0;

    while (fabs(f(x)) > eps) {
        double derivative = df(x);
        if (fabs(derivative) < 1e-12) {
            cout << "Похідна близька до нуля. Метод Ньютона не може продовжити." << endl;
            return x;
        }
        x = x - f(x) / derivative;
        iter++;
        if (iter > 1000) {
            cout << "Перевищено максимальну кількість ітерацій!" << endl;
            break;
        }
    }
    return x;
}

double Equation_class::solveNewton(double start_x, double vol_eps) {
    setStart(start_x);
    setTolerance(vol_eps);
    return solveNewton();
}
