/**
 * title: 智障循迹小车控制代码
 * author: Palm Civet
 */
#include <Servo.h>
Servo myservo;

// define the port of sensor and the value of port.
const pin_L1 = 5;
const pin_L2 = 5;
const pin_R2 = 5;
const pin_R1 = 5;

int val_L1;
int val_L2;
int val_R2;
int val_R1;

// define the signal.
const black = 1; // HIGH
const white = 0; // LOW

// angle.
const angle_mid = 90;
const angle_left = 10;
const angle_right = 80;

int angle_cur = angle_mid;
int angle_chge = 5;

// verify the input angle.
void angle_verify(int angle_chge, int angle_cur)
{
    if ((angle_chge + angle_cur) > angle_left && (angle_chge + angle_cur) < angle_right)
    {
        myservo.write(angle_cur + angle_chge);
        delay(50);
    }
}
void status_read()
{
    val_L1 = digitalRead(pin_L1);
    val_L2 = digitalRead(pin_L2);
    val_R2 = digitalRead(pin_R2);
    val_R1 = digitalRead(pin_R1);
}

void setup()
{
    // set up port of sensor as input.
    pinMode(pin_L1, OUTPUT);
    pinMode(pin_L2, OUTPUT);
    pinMode(pin_R2, OUTPUT);
    pinMode(pin_R1, OUTPUT);

    // init the servo.
    myservo.attach(9);
    myservo.write(angle_mid);

    Serial.begin(9600);
}

void loop()
{
    status_read();
}

int turn()
{
    /* TCRT5000 红外对管传感器参数
     * 检测距离：1~25 mm
     * 工作电压：3.3~5 V
     * 工作原理：红外发射二极管发射红外线，当发射出的红外线未被反射则输出高电平
     * 输出：AO - 模拟信号
     * black - HIGH - 1
     * white - LOW  - 0
     */
    if ((val_L1 == black) || (val_R1 == black)) // turn left
    {
        // turn left
        if (val_L1 == black)
        {
            angle_chge = 5;
        }
        // turn right
        else
        {
            angle_chge = -5;
        }
    }
    else
    {
    }
    return angle_chge;
}
