#ifndef METHODS_H
#define METHODS_H

class Equation_class
{
private:
    double a, b, x0, eps;
    static double f(double x);
    static double df(double x);

public:
    void setVolumes(double vol_a, double vol_b);
    void setStart(double start_x);
    void setTolerance(double vol_eps);

    double solveDyhotomia();
    double solveDyhotomia(double vol_a, double vol_b, double vol_eps);

    double solveNewton();
    double solveNewton(double start_x, double vol_eps);
};

#endif
