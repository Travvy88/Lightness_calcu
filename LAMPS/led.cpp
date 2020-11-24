#include "led.h"

void LED::setIntencity(int red_, int green_, int blue_) {
    red = red_;
    green = green_;
    blue = blue_;

    intencity = 0.299 * red + 0.587 * green + 0.114 * blue;
    if (intencity < MIN_I)
            intencity = MIN_I;
    else if (intencity > MAX_I)
            intencity = MAX_I;

}

int LED::getRed() const {
    return red;
}

int LED::getBlue() const {
    return blue;
}

bool LED::operator==(const LED &l) const
{
    if (l.getPower()==this->getPower() && l.getRed()==this->getRed()
             && l.getBlue()==this->getBlue()
             && l.getGreen()==this->getGreen())
        return 1;
    else
        return 0;
}

int LED::getGreen() const {
    return green;
}
