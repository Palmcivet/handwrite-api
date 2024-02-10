#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define X_AXIS 34
#define Y_AXIS 18

void MP_Circle(int r)
{
    int x, y;
    double d;

    x = 0;
    y = r;
    d = 1.25 - r;
    printf("before: %d %d\n", x, y);
    while (x < y)
    {
        if (d < 0)
        {
            d = d + 2 * x + 3;
        }
        else
        {
            d = d + 2 * (x - y) + 5;
            y--;
        }
        x++;
        printf("after: %d %d\n", x, y);
    }
}

int main()
{
    int a;
    printf("=============== Example =================\n");
    scanf("%d", &a);
    for (int y = -Y_AXIS; y <= Y_AXIS; y += 1)
    {
        for (int x = -X_AXIS; x <= X_AXIS; x += 1)
        {
            MP_Circle(a);
            // if (y * y + x * x == a * a)
            //{
            //     //printf("%f %f\n", y, x);
            // }
        }
    }
    return 0;
}
