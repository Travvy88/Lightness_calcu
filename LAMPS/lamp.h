#ifndef LAMP_H
#define LAMP_H


class Lamp
{
public:
    Lamp(int p = DEFAULT_P, int i = DEFAULT_I);
    Lamp(const Lamp &other);

    float getPower() const;
    float getIntencity() const;
    void setPower(const int values);
    void setIntencity(const int values);
    bool operator==(const Lamp&) const;

protected:
    float intencity;
    float power;

    static const int MIN_I = 1;
    static const int MAX_I = 1000;
    static const int DEFAULT_P = 300;

private:
    static const int DEFAULT_I = 100;
    static const int MAX_P = 1000;
    static const int MIN_P = 1;
};

#endif // LAMP_H
