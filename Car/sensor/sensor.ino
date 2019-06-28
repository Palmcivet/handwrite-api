#include <Servo.h>
Servo myservo;

void setSpeed(int pin1, int pin2, int period, float percent)
{
    if (percent > 100 || percent < 0)
    {
        return 0;
    }
    else
    {
        percent /= 100;
    }
    digitalWrite(pin2, LOW);
    digitalWrite(pin1, HIGH);
    digitalWrite(pin1, LOW);
}

void setup()
{
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    myservo.attach(7);
    myservo.write(90);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
}

void loop()
{
}
