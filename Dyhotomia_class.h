#ifndef DYHOTOMIA_CLASS_H
#define DYHOTOMIA_CLASS_H

class Dyhotomia_class
{
private:
    double a;
    double b;
    double eps;
    static double f(double x);

public:
    void setVolumes(double vol_a, double vol_b);
    void setTolerance(double vol_eps);
    double solve();
    double solve(double vol_a, double vol_b, double vol_eps);
};

#endif
