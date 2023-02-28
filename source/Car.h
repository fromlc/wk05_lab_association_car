//------------------------------------------------------------------------------
// Car, Engine, AutoTrans : class declarations and definitions
// 
// - Car class has member variables of type Engine, type AutoTrans
// - Setting Car's gas pedal sets Engine's rpms
// - Setting Engine's rpms sets AutoTrans' gear
// - From app code, get Engine's rpms with Car::getRpms()
// - From app code, get AutoTrans' gear with Car::getGear()
//------------------------------------------------------------------------------
#pragma once

//------------------------------------------------------------------------------
// AutoTrans
//------------------------------------------------------------------------------
class AutoTrans {
private:
    int gear;

public:
    AutoTrans() : gear(0) { }

    void setGear(int _gear) { gear = _gear; };
    int getGear() const { return gear; }
};

//------------------------------------------------------------------------------
// Engine
//------------------------------------------------------------------------------
class Engine {
private:
    int rpms;

public:
    Engine() : rpms(0) { }

    void setRpms(int _rpms, AutoTrans& at) {
        rpms = _rpms * 1000;

        at.setGear(rpms / 2000);
    }

    int getRpms() const { return rpms; }
};

//------------------------------------------------------------------------------
// Car : compositions Engine and AutoTrans
//------------------------------------------------------------------------------
class Car {
private:
    int gasPedal;
    Engine v8;
    AutoTrans tranny;

public:
    Car() : gasPedal(0) { }

    // gas pedal controls engine rpms and transmission gear
    void setGasPedal(int gasAmount) {
        gasPedal = gasAmount;

        // engine needs to know which transmission to shift
        v8.setRpms(gasPedal, tranny);
    }

    // get gas pedal level
    int getGasPedal() const { return gasPedal; }

    // getters for engine and transmission data
    int getRpms() const { return v8.getRpms(); }
    int getGear() const { return tranny.getGear(); }
};
