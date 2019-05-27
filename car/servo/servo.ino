// 测试舵机角度
#include <Servo.h>
Servo myservo;

void setup()
{
	pinMode(7, OUTPUT);
	myservo.attach(7);
  myservo.write(90);
}

void loop()
{
	myservo.write(50);
	//delay(500);
}
