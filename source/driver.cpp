//------------------------------------------------------------------------------
// driver.cpp : test driver for association testing with Car, Engine, AutoTrans
//------------------------------------------------------------------------------

#include "Car.h"

#include <iostream>

//------------------------------------------------------------------------------
// using symbols
//------------------------------------------------------------------------------
using std::cin;
using std::cout;

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------
constexpr int GASMAX = 6;
constexpr int ENGINESLEFT = 3;

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------
void displayBanner();
void inputLoop();

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

    displayBanner();

    inputLoop();

    cout << "Goodbye!\n\n";

    return 0;
}

//------------------------------------------------------------------------------
// app setup
//------------------------------------------------------------------------------
void displayBanner() {

    cout << "\nDrive a GTO!\n";
    cout << "Enter gas amounts from 1 to " << GASMAX << ", 0 quits.\n";
    cout << "You can blow up to " << ENGINESLEFT << " engines.\n\n";
}

//------------------------------------------------------------------------------
// process user commands
//------------------------------------------------------------------------------
void inputLoop() {

    Car gto;
    int enginesLeft = ENGINESLEFT;

    while (enginesLeft) {

        cout << "How much gas? ";
        int gasAmount;
        cin >> gasAmount;

        // quit on 0 gas
        if (!gasAmount) {
            break;
        }

        // hit the gas
        gasAmount = abs(gasAmount);
        if (gasAmount > GASMAX) {
            cout << "GTO engine blown! Engines left: "
                << --enginesLeft << "\n\n";
            continue;
        }

        // gas pedal controls engine rpms and transmission gear
        gto.setGasPedal(gasAmount);

        cout << "Gas pedal: " << gto.getGasPedal() << '\n';
        cout << "Engine RPMs: " << gto.getRpms() << '\n';

        int gear = gto.getGear() + 1;
        cout << "Transmission gear: " << gear << '\n';

        cout << "Vroom";
        for (int i = 0; i < gear; ++i) {
            cout << '!';
        }
        cout << "\n\n";
    }
}