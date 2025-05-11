#include "Methods.h"
#include <iostream>
#include <cmath>

using namespace std;

void Dyhotomia_class::setVolumes(double vol_a, double vol_b){
    a = vol_a;
    b = vol_b;
}

void Dyhotomia_class::setTolerance(double vol_eps){
    eps = vol_eps;
}

double Dyhotomia_class::solve(){
    while (fabs(b - a) > eps)
    {
        double c = (a + b) / 2.0;
        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
    }
    return (a + b) / 2.0;
}

double Dyhotomia_class::solve(double vol_a, double vol_b, double vol_eps){
    setVolumes(vol_a, vol_b);
    setTolerance(vol_eps);
    return solve();
}

double Dyhotomia_class::f(double x){
    return cos(x) - exp(-x * x / 2.0) + x - 1.0;
}

void Newton_class::setStart(double start_x){
    x0 = start_x;
}

void Newton_class::setTolerance(double vol_eps){
    eps = vol_eps;
}

double Newton_class::f(double x){
    return cos(x) - exp(-x * x / 2.0) + x - 1.0;
}

double Newton_class::df(double x){
    double h = 1e-6;
    return (f(x + h) - f(x)) / h;
}

double Newton_class::solve(){
    double x = x0;
    int iter = 0;

    while (fabs(f(x)) > eps){
        double derivative = df(x);
        if (fabs(derivative) < 1e-12){
            cout << "Похідна близька до нуля. Метод Ньютона не може продовжити." << endl;
            return x;
        }
        x = x - f(x) / derivative;
        iter++;
        if (iter > 100){
            cout << "Перевищено максимальну кількість ітерацій!" << endl;
            break;
        }
    }
    return x;
}

double Newton_class::solve(double start_x, double vol_eps){
    setStart(start_x);
    setTolerance(vol_eps);
    return solve();
}