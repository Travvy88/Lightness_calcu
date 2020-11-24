#include "cell.h"

Cell::Cell() {
    data.lamp = nullptr;
    data.led = nullptr;
    type = -1;
}

int Cell::getTypeOfLight() const {
    return type;
}

void Cell::setLamp()
{
    data.lamp = new Lamp();
    type = 0;
}

void Cell::setLamp(Lamp l) {
    data.lamp = new Lamp(l);
    type = 0;
}

void Cell::setLED()
{
    data.led = new LED();
    type = 1;
}

void Cell::setLED(LED l) {
    data.led = new LED (l);
    type = 1;
}

Lamp &Cell::getLamp() const
{
    return *data.lamp;
}

LED &Cell::getLED() const
{
    return *data.led;
}

bool Cell::operator==(const Cell &c) const
{
    int type1 = c.getTypeOfLight();
    int type2 = this->getTypeOfLight();

    if (type1 != type2)
        return 0;
    else if (type1 == -1)
        return 1;
    else if (type1 ==0 && c.getLamp() == this->getLamp())
        return 1;
    else if (type1 ==1 && c.getLED() == this->getLED())
        return 1;

}
