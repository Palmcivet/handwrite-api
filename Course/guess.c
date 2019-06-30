#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int a, b, i = 0, t;
    srand(time(0));
    t = time(0);
    a = rand() % 10;
    printf("%d\n", a);
    printf("|-----------------------------------------------------|\n");
    printf("|-------------------欢迎来到猜数游戏------------------|\n");
    printf("|-------------WELCOME TO THE GUESSING GAME------------|\n");
    printf("|---------------现在输入一个你喜欢的数字吧------------|\n");
    printf("|-------------NOW ENTER A NUMBER YOU LIKE-------------|\n");
    printf("|-----------------------------------------------------|\n");
    printf("\n");
    printf("你的数字：");
    scanf("%d", &b);
    while (b != a)
    {
        if (b > a)
            printf("你输入的数字大了哟，再来一次吧\n");
        else
            printf("你输入的数字小了哟，再来一次吧\n");

        i++;
        scanf("%d", &b);
    }
    if (b == a)
        printf(" 你真棒，猜对啦！\n");
    t = time(0) - t;
    printf("|-----------------------------------------------------|\n");
    printf("你猜了： %d 次\n,用时： %d 秒", i + 1, t);
}