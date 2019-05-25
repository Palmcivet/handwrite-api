void setMotor(int MOTORA，int MOTORB)
{
    if(MOTORA>0) //判断方向，大于0表示正向
    {
        digitalWrite(DIRA，HIGH); //DIRA引脚置高
        analogWrite(PWMA，255 + MOTORA); //PWMA输入PWM信号
        //PWM是高电平的占空比，这里需要取反，所以255 + MOTORA
    }
    else if(MOTORA<0) //判断方向，小于0表示反向
    {
        digitalWrite(DIRA，LOW);
        analogWrite(PWMA，255 - MOTORA); //PWM是高电平的占空比
        //这里需要取反，这时MOTORA为负值，所以255 - MOTORA
    }
    else //等于0表示停止
    {
        digitalWrite(DIRA，LOW);
        analogWrite(PWMA，LOW);
    }

    if(MOTORB>0) //判断方向，大于0表示正向
    {
        digitalWrite(DIRB，HIGH); //DIRB引脚置高
        analogWrite(PWMB，255 + MOTORB); //PWMB输入PWM信号
        //PWM是高电平的占空比，这里需要取反，所以255 + MOTORB
    }
    else if(MOTORB<0) //判断方向，小于0表示反向
    {
        digitalWrite(DIRB，LOW);
        analogWrite(PWMB，255 - MOTORB); //PWM是高电平的占空比
        //这里需要取反，这时MOTORB为负值，所以255 - MOTORB
    }
    else //等于0表示停止
    {
        digitalWrite(DIRB，LOW);
        analogWrite(PWMB，LOW);
    }
}
