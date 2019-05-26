/**
 * title: the Code for Mentally Car
 * author: Palm Civet
 * version: 1.2
 * Comment:
 */
#include <Servo.h>
#include <Stepper.h>
#define black 1 // HIGH
#define white 0 // LOW

Servo myservo;

// signal of steeper, use pwm.
const int port_stepper = 6;
int val_stepper;

// signal of servo.
const int port_servo = 7;
int val_servo;

// define the digital port of sensor and the value of port.
const int port_R1_D = 8;
const int port_R2_D = 9;
const int port_L2_D = 10;
const int port_L1_D = 11;

int val_L1_D;
int val_L2_D;
int val_R2_D;
int val_R1_D;

// TODO below ===================
// define the analog port of sensor and the value of port.
const int port_L1_A = A0;
const int port_L2_A = A1;
const int port_R2_A = A2;
const int port_R1_A = A3;

int val_L1_A;
int val_L2_A;
int val_R2_A;
int val_R1_A;

// to verify the angles.
const int angle_mid = 90;
const int angle_left = 45;
const int angle_right = 135;

int angle_chge;

// TODO above ===================

void superturnL()
{
	angle_chge = 70;
	myservo.write(angle_chge);
	Serial.println("superLeft");
}
void turnL()
{
	angle_chge = 80;
	myservo.write(angle_chge);
	Serial.println("Left");
}
void turnR()
{
	angle_chge = 100;
	myservo.write(angle_chge);
	Serial.println("Right");
}
void superturnR()
{
	angle_chge = 110;
	myservo.write(angle_chge);
	Serial.println("superRight");
}
void strT()
{
	angle_chge = 90;
	myservo.write(angle_chge);
	Serial.println("Straight");
}
void Stop()
{
	angle_chge = 90;
	myservo.write(angle_chge);
	analogWrite(val_servo, 0);
	Serial.println("Stop");
}

void setup()
{
	//digitalWrite(stepper_1, HIGH);
	//digitalWrite(stepper_2, LOW);
	pinMode(port_servo, OUTPUT);
	myservo.attach(port_servo);

	strT();

	pinMode(port_L1_D, INPUT);
	pinMode(port_L2_D, INPUT);
	pinMode(port_R2_D, INPUT);
	pinMode(port_R1_D, INPUT);

	// TODO
	pinMode(port_L1_A, INPUT);
	pinMode(port_L2_A, INPUT);
	pinMode(port_R2_A, INPUT);
	pinMode(port_R1_A, INPUT);
	Serial.begin(9600);
}

void loop()
{
	val_L1_D = digitalRead(port_L1_D);
	val_L2_D = digitalRead(port_L2_D);
	val_R2_D = digitalRead(port_R2_D);
	val_R1_D = digitalRead(port_R1_D);

	// TODO
	val_L1_A = digitalRead(port_L1_A);
	val_L2_A = digitalRead(port_L2_A);
	val_R2_A = digitalRead(port_R2_A);
	val_R1_A = digitalRead(port_R1_A);

	/* TCRT5000 红外对管传感器参数
     * 检测距离：1~25 mm
     * 工作电压：3.3~5 V
     * 工作原理：红外发射二极管发射红外线，当发射出的红外线未被反射则输出高电平
     * 输出：AO - 模拟信号
	 * 		DO - 数字信号
     * black - HIGH - 1 - off
     * white - LOW  - 0 - on
     */

	if ((val_L1_D & val_L2_D & val_R2_D & val_R1_D) == black)
	{
		Stop();
	}

	if ((val_L1_D || val_L2_D) == black)
	{
		if (val_L1_D == black)
		{
			turnL();
		}
		if (val_L2_D == black)
		{
			superturnL();
		}
	}

	if ((val_R2_D || val_R1_D) == black)
	{
		if (val_R2_D == black)
		{
			turnR();
		}
		if (val_R1_D == black)
		{
			superturnR();
		}
	}
}