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
    delay(period * percent);
    digitalWrite(pin1, LOW);
    delay(period * (1 - percent));
}

void setup()
{
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    myservo.attach(7);
    myservo.write(90);
}

void loop()
{
    //setSpeed(5, 6, 100, 50);
    setSpeed(5, 6, 500, 50);
//    delay(500);
}
