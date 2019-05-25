const int sensor_L1_D = 12;
const int sensor_L1_A = A0;
int val_L1_D;
int val_L1_A;

void setup()
{
    pinMode(sensor_L1_D, INPUT);
    pinMode(sensor_L1_A, INPUT);
    Serial.begin(9600);
}

void loop()
{
    val_L1_D = digitalRead(sensor_L1_D);
    val_L1_A = analogRead(sensor_L1_A);
    Serial.print("signal:");
    Serial.print(val_L1_D);
    Serial.print(" : ");
    Serial.println(val_L1_A);
    delay(700);
}
