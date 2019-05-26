// 测试舵机角度
#include <Servo.h>
Servo myservo;

void setup()
{
	pinMode(6, OUTPUT);
	myservo.attach(6);
  myservo.write(90);
}

void loop()
{
	myservo.write(90);
	delay(500);
}
