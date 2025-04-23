#include "Dyhotomia_class.h"
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
