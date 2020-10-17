#include "lamp.h"

Lamp::Lamp(int p, int i){
    setPower(p);
    setIntencity(i);
}

Lamp::Lamp(const Lamp &other){
    power = other.power;
    intencity = other.intencity;
}

int Lamp::getPower() const{
    return power;
}

int Lamp::getIntencity() const{
    return intencity;
}

void Lamp::setPower(const int values){
    if (values > MAX_P)
        power = MAX_P;
    else if (values < MIN_P)
        power = MIN_P;
    else
        power = values;
}

void Lamp::setIntencity(const int values){
    if (values > MAX_I)
        intencity = MAX_I;
    else if (values < MIN_I)
        intencity = MIN_I;
    else
        intencity = values;
}

