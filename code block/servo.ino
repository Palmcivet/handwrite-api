// 测试舵机角度
#include <Servo.h>
Servo myservo;

String tmp;
int angle = 1500;

void setup()
{
    myservo.attach(9);
    Serial.begin(9500);
    myservo.writeMicroseconds(angle);
}

void loop()
{
    if (Serial.available())
    {
        tmp = Serial.read();
        angle = tmp.toInt();
        if ((angle <= 2000) && (angle >= 1000))
        {
            myservo.writeMicroseconds(angle);
            Serial.println(angle, DEC);
        }
    }
    delay(15);
}