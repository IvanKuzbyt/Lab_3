#include <iostream>
#include "Dyhotomia_class.cpp"

using namespace std;

int main(){
    setlocale (LC_ALL, "uk_UA.UTF-8");

    Dyhotomia_class* dyh = new Dyhotomia_class();
    dyh->setVolumes(1,2);
    dyh->setTolerance(1e-8);

    cout << " Рiвняння :\n cos(x) – exp(–x^2 / 2) + x – 1" << endl;
    cout << " Результат : " << dyh->solve() << endl << endl;

    delete(dyh);

    return 0;
}
