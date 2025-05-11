#include <iostream>
#include "Methods.cpp"

using namespace std;

int main(){
    setlocale(LC_ALL, "uk_UA.UTF-8");

    Dyhotomia_class* dyh = new Dyhotomia_class();
    dyh->setVolumes(1, 2);
    dyh->setTolerance(1e-8);

    cout << "Метод дихотомiї:" << endl;
    cout << "Рiвняння: cos(x) – exp(–x^2 / 2) + x – 1" << endl;
    cout << "Результат: " << dyh->solve() << endl;

    delete(dyh);

    Newton_class* newt = new Newton_class();
    newt->setStart(1.5);
    newt->setTolerance(1e-8);

    cout << "\nМетод Ньютона:" << endl;
    cout << "Рiвняння: cos(x) – exp(–x^2 / 2) + x – 1" << endl;
    cout << "Результат: " << newt->solve() << endl;

    delete(newt);

    return 0;
}