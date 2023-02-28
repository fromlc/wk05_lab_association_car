//------------------------------------------------------------------------------
// driver.cpp : test driver for association testing with Car, Engine, AutoTrans
//------------------------------------------------------------------------------

#include "Car.h"

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

    Car gto;

    gto.setGasPedal(2);

    cout << "Gas pedal: " << gto.getGasPedal() << '\n';
    cout << "Engine RPMs: " << gto.getRpms() << '\n';
    cout << "Transmission gear: " << gto.getGear() << '\n';

    cout << "\nVroom!!\n\n";

    return 0;
}
