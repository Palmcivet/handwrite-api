/**
 * title: the Code to Mentally Car
 * author: Palm Civet
 */
#include <Servo.h>
Servo myservo;

// define PWM port.
const servo = 9;
const stepper_1 = 10;
const stepper_2 = 11;

// define the signal of sensor.
const black = 1; // HIGH
const white = 0; // LOW

// define the port of sensor and the value of port.
const sensor_L1 = 2;
const sensor_L2 = 3;
const sensor_R2 = 4;
const sensor_R1 = 5;

char val_L1;
char val_L2;
char val_R2;
char val_R1;

// as for angle.
const angle_mid = 90;
const angle_left = 10;
const angle_right = 80;

int angle_chge;

void turnL()
{
	angle_chge = 50;
	myservo.write(angle_chge);
	analogWrite(stepper_1, 90);
	Serial.println("Left");
}
void superturnL()
{
	angle_chge = 30;
	myservo.write(angle_chge);
	analogWrite(stepper_1, 90);
	Serial.println("superLeft");
}
void turnR()
{
	angle_chge = 90;
	myservo.write(angle_chge);
	analogWrite(stepper_1, 90);
	Serial.println("Right");
}
void superturnR()
{
	angle_chge = 120;
	myservo.write(angle_chge);
	analogWrite(stepper_1, 90);
	Serial.println("superRight");
}
void strT()
{
	angle_chge = 70;
	myservo.write(angle_chge);
	analogWrite(stepper_1, 90);
	Serial.println("Straight");
}
void Stop()
{
	angle_chge = 70;
	myservo.write(angle_chge);
	analogWrite(stepper_1, 0);
	Serial.println("Stop");
}

void setup()
{
	pinMode(stepper_1, OUTPUT);
	myservo.attach(port_servo);
	pinMode(sensor_L1, INPUT);
	pinMode(sensor_L2, INPUT);
	pinMode(sensor_R2, INPUT);
	pinMode(sensor_R1, INPUT);
	Serial.begin(9600);
}

void loop()
{
	analogWrite(stepper_1, 90);

	val_L1 = digitalRead(sensor_L1);
	val_L2 = digitalRead(sensor_L2);
	val_R2 = digitalRead(sensor_R2);
	val_R1 = digitalRead(sensor_R1);

	int a = 0;
	int carstop = 0;
    
	/* TCRT5000 红外对管传感器参数
     * 检测距离：1~25 mm
     * 工作电压：3.3~5 V
     * 工作原理：红外发射二极管发射红外线，当发射出的红外线未被反射则输出高电平
     * 输出：AO - 模拟信号
	 * 		DO - 数字信号
     * black - HIGH - 1
     * white - LOW  - 0
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
