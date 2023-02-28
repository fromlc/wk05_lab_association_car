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
bool hitTheGas(Car&, int, int&);
void displayDashboard(Car&);

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

    displayBanner();

    inputLoop();

    return 0;
}

//------------------------------------------------------------------------------
// app setup
//------------------------------------------------------------------------------
void displayBanner() {

    cout << "\nDrive a GTO!\n";
    cout << "Enter how hard to hit the gas pedal (1 to " 
        << GASMAX << "), 0 quits.\n";
    cout << "Hit the gas too hard and you'll blow the engine!\n";
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

        // 0 gas means user wants to quit app
        if (!gasAmount) {
            cout << '\n';
            break;
        }

        if (hitTheGas(gto, gasAmount, enginesLeft)) {
            displayDashboard(gto);
        }
    }
    
    cout << "Goodbye!\n\n";
}

//------------------------------------------------------------------------------
// - sets car's gas pedal level, which sets engine rpms and transmission gear
// - updates enginesLeft reference parameter
// - returns false on blown engine, true otherwise
//------------------------------------------------------------------------------
bool hitTheGas(Car& gto, int gasAmount, int& enginesLeft) {

    gasAmount = abs(gasAmount);

    if (gasAmount > GASMAX) {
        cout << "GTO engine blown! Engines left: "
            << --enginesLeft << "\n\n";
        return false;
    }

    // gas pedal controls engine rpms and transmission gear
    gto.setGasPedal(gasAmount);

    return true;
}

//------------------------------------------------------------------------------
// display results of setting car's gas pedal
//------------------------------------------------------------------------------
void displayDashboard(Car& gto) {

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