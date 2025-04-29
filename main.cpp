#include <iostream>
#include "Methods.cpp"

using namespace std;

int main() {
    setlocale(LC_ALL, "uk_UA.UTF-8");

    Equation_class solver;

    solver.setVolumes(1, 2);
    solver.setTolerance(1e-8);

    cout << "Метод дихотомiї:" << endl;
    cout << "Рiвняння: cos(x) – exp(–x^2 / 2) + x – 1" << endl;
    cout << "Результат: " << solver.solveDyhotomia() << endl << endl;

    solver.setStart(1.5);
    solver.setTolerance(1e-8);

    cout << "Метод Ньютона:" << endl;
    cout << "Рiвняння: cos(x) – exp(–x^2 / 2) + x – 1" << endl;
    cout << "Результат: " << solver.solveNewton() << endl;

    return 0;
}
