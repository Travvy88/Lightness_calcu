#ifndef CELL_H
#define CELL_H
#include "lamp.h"
#include "led.h"

class Cell
{
public:
    Cell();
    int getTypeOfLight() const;
    void setLamp();
    void setLamp(Lamp l);
    void setLED();
    void setLED(LED l);
    Lamp &getLamp() const;
    LED &getLED() const;
    bool operator==(const Cell&) const;
private:
    struct Data {
        Lamp *lamp;
        LED *led;
    }data;
    int type; // 0 - Lamp, 1 - LED, -1 - nothing
};

#endif // CELL_H
