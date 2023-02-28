//------------------------------------------------------------------------------
// Car, Engine, AutoTrans,  : class declarations and definitions
//------------------------------------------------------------------------------
#pragma once

//------------------------------------------------------------------------------
// Engine
//------------------------------------------------------------------------------
class Engine {
private:
    int rpms;

public:
    Engine() : rpms(0) { }

    void setRpms(int _rpms) { rpms = _rpms; }
    int getRpms() const { return rpms; }
};

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
// Car, Engine, AutoTrans,  : class declarations and definitions
//------------------------------------------------------------------------------
class Car {
private:
    int gasPedal;
    Engine v8;
    AutoTrans tranny;

public:
    Car() : gasPedal(0) { }

    void setGasPedal(int gas) { gasPedal = gas; }
    int getGasPedal() const { return gasPedal; }
};

