/**
 * title: the Code to Mentally Car
 * author: Palm Civet
 */
#include <Servo.h>
Servo myservo;

// define the signal of sensor.
const int black = 1; // HIGH
const int white = 0; // LOW

// define PWM port.
const int servo = 9;
const int stepper_1 = 10; // HIGH
const int stepper_2 = 11; // LOW

// define the port of sensor and the value of port.
const int sensor_L1_D = 13;
const int sensor_L2_D = 12;
const int sensor_R2_D = 8;
const int sensor_R1_D = 7;

int val_L1_D;
int val_L2_D;
int val_R2_D;
int val_R1_D;

// TODO
const int sensor_L1_A = A0;
const int sensor_L2_A = A1;
const int sensor_R2_A = A2;
const int sensor_R1_A = A3;

int val_L1_A;
int val_L2_A;
int val_R2_A;
int val_R1_A;

// TODO
// to verify the angles.
const int angle_mid = 90;
const int angle_left = 10;
const int angle_right = 80;

int angle_chge;

void superturnL()
{
	angle_chge = 50;
	myservo.write(angle_chge);
	analogWrite(stepper_1, 90);
	Serial.println("superLeft");
}
void turnL()
{
	angle_chge = 70;
	myservo.write(angle_chge);
	analogWrite(stepper_1, 90);
	Serial.println("Left");
}
void turnR()
{
	angle_chge = 110;
	myservo.write(angle_chge);
	analogWrite(stepper_1, 90);
	Serial.println("Right");
}
void superturnR()
{
	angle_chge = 130;
	myservo.write(angle_chge);
	analogWrite(stepper_1, 90);
	Serial.println("superRight");
}
void strT()
{
	angle_chge = 90;
	myservo.write(angle_chge);
	analogWrite(stepper_1, 90);
	Serial.println("Straight");
}
void Stop()
{
	angle_chge = 90;
	myservo.write(angle_chge);
	analogWrite(stepper_1, 0);
	Serial.println("Stop");
}

void setup()
{
	pinMode(stepper_1, OUTPUT);
	myservo.attach(port_servo);
	myservo.write(angle_mid);
	pinMode(sensor_L1_D, INPUT);
	pinMode(sensor_L2_D, INPUT);
	pinMode(sensor_R2_D, INPUT);
	pinMode(sensor_R1_D, INPUT);
	
	pinMode(sensor_L1_A, INPUT);
	pinMode(sensor_L2_A, INPUT);
	pinMode(sensor_R2_A, INPUT);
	pinMode(sensor_R1_A, INPUT);
	Serial.begin(9600);
}

void loop()
{
	analogWrite(stepper_1, 90);

	val_L1_D = digitalRead(sensor_L1_D);
	val_L2_D = digitalRead(sensor_L2_D);
	val_R2_D = digitalRead(sensor_R2_D);
	val_R1_D = digitalRead(sensor_R1_D);

	val_L1_A = digitalRead(sensor_L1_A);
	val_L2_A = digitalRead(sensor_L2_A);
	val_R2_A = digitalRead(sensor_R2_A);
	val_R1_A = digitalRead(sensor_R1_A);

	int a = 0;
	int carstop = 0;

	/* TCRT5000 红外对管传感器参数
     * 检测距离：1~25 mm
     * 工作电压：3.3~5 V
     * 工作原理：红外发射二极管发射红外线，当发射出的红外线未被反射则输出高电平
     * 输出：AO - 模拟信号
	 * 		DO - 数字信号
     * black - HIGH - 1 - off
     * white - LOW  - 0 - on
     */

	if ((val_L1 || val_L2) == 1)
	{
		if (val_L1 == 1)
		{
			superturnL();
		}
		if (val_L2 == 1)
		{
			turnL();
		}
		if ((val_L1 & val_L2 & val_R2 & val_R1) == 1)
		{
			Stop();
		}
	}

	if ((val_R2 || val_R1) == 1)
	{
		if (val_R1 == 1)
		{
			superturnR();
		}
		if (val_R2 == 1)
		{
			turnR();
		}
		if ((val_L1 & val_L2 & val_R2 & val_R1) == 1)
		{
			Stop();
		}
	}
}
