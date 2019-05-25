float Kp = 10, Ki = 0.5, Kd = 0;
float error = 0, P = 0, I = 0, D = 0, PID_value = 0;
float previous_error = 0, previous_I = 0;
int sensor[5] = {0, 0, 0, 0, 0};
static int initial_motor_speed = 60;

void read_sensor_values(void);
void calc_pid(void);
void motor_control(void);

// The pins used:
const int IN_A1 = 3;  // Motor A input A
const int IN_A2 = 9;  // Motor A input B
const int IN_B1 = 10; // Motor B input A
const int IN_B2 = 11; // Motor B input B

void setup()
{
    // set up motor control pins as output
    pinMode(IN_A1, OUTPUT);
    pinMode(IN_A2, OUTPUT);
    pinMode(IN_B1, OUTPUT);
    pinMode(IN_B2, OUTPUT);

    pinMode(4, INPUT);
    pinMode(5, INPUT);
    pinMode(6, INPUT);
    pinMode(7, INPUT);
    pinMode(8, INPUT);

    Serial.begin(9600); //Enable Serial Communications
}

void loop()
{
    read_sensor_values();
    calc_pid();
    motor_control();
}

//速度设定范围(-255,255)
void motorsWrite(int speedL, int speedR)
{
    if (speedR > 0)
    {
        analogWrite(IN_A1, speedR);
        analogWrite(IN_A2, 0);
    }
    else
    {
        analogWrite(IN_A1, 0);
        analogWrite(IN_A2, -speedR);
    }

    if (speedL > 0)
    {
        analogWrite(IN_B1, speedL);
        analogWrite(IN_B2, 0);
    }
    else
    {
        analogWrite(IN_B1, 0);
        analogWrite(IN_B2, -speedL);
    }
}

//速度设定范围(-100，100)
void motorsWritePct(int speedLpct, int speedRpct)
{
    //speedLpct, speedRpct ranges from -100 to 100
    motorsWrite(speedLpct * 2.55, speedRpct * 2.55);
}
void motorsStop()
{
    analogWrite(IN_A1, 0);
    analogWrite(IN_A2, 0);

    analogWrite(IN_B1, 0);
    analogWrite(IN_B2, 0);
}

void read_sensor_values()
{
    sensor[0] = digitalRead(4);
    sensor[1] = digitalRead(5);
    sensor[2] = digitalRead(6);
    sensor[3] = digitalRead(7);
    sensor[4] = digitalRead(8);

    if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 1))
    {
        error = 2;
    }
    else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 0))
    {
        error = 1;
    }
    else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 1) && (sensor[3] == 0) && (sensor[4] == 0))
    {
        error = 0;
    }
    else if ((sensor[0] == 0) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 0))
    {
        error = -1;
    }
    else if ((sensor[0] == 1) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 0))
    {
        error = -2;
    }
    else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 0))
    {
        if (error == -2)
        {
            error = -3;
        }
        else
        {
            error = 3;
        }
    }
}

void calc_pid()
{
    P = error;
    I = I + error;
    D = error - previous_error;

    PID_value = (Kp * P) + (Ki * I) + (Kd * D);
    previous_error = error;
}

void motor_control()
{
    int left_motor_speed = initial_motor_speed - PID_value;
    int right_motor_speed = initial_motor_speed + PID_value;

    if (left_motor_speed < -255)
    {
        left_motor_speed = -255;
    }
    if (left_motor_speed > 255)
    {
        left_motor_speed = 255;
    }
    motorsWrite(left_motor_speed, right_motor_speed);

    Serial.print("move_A: ");
    Serial.print(left_motor_speed, OCT);
    Serial.print(" move_B: ");
    Serial.print(right_motor_speed, OCT);
    Serial.print(" error: ");
    Serial.print(error, OCT);
    Serial.print(" P: ");
    Serial.print(Kp, OCT);
    Serial.print(" PID_value: ");
    Serial.print(PID_value, OCT);
    Serial.println();
}