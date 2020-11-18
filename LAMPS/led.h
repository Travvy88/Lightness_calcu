#ifndef LED_H
#define LED_H
#include <string>
#include "lamp.h"

class LED: Lamp {
public:
    virtual void setIntencity(int, int, int);
    int getRed() const;
    int getGreen() const;
    int getBlue() const;



private:
    int red, green, blue;

};

#endif // LED_H
