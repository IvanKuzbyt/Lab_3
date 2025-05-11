#ifndef ALL_METHODS_H
#define ALL_METHODS_H

class Dyhotomia_class
{
private:
double a, b;
double eps;
static double f(double x);

public:
void setVolumes(double vol_a, double vol_b);
void setTolerance(double vol_eps);
double solve();
double solve(double vol_a, double vol_b, double vol_eps);
};

class Newton_class
{
private:
double x0;
double eps;
static double f(double x);
static double df(double x);

public:
void setStart(double start_x);
void setTolerance(double vol_eps);
double solve();
double solve(double start_x, double vol_eps);
};

#endif
