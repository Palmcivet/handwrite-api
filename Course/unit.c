#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define X_AXIS 34
#define Y_AXIS 18

int main()
{
    printf("=============== Example =================\n");
    for (int y = -Y_AXIS; y <= Y_AXIS; y++)
    {
        for (int x = -X_AXIS; x <= X_AXIS; x++)
        {
            float a = 10.0, b = 10.0;
            //if (y * y / a / a + x * x / b / b == 1)
            if (y * y / a / a + x * x / b / b == 1.0)
            {
                //printf("%d %d\n", y, x);
                printf("%d*%d/%f/%f + %d*%d/%f/%f\n", y, y, a, a, x, x, b, b);
            }
        }
    }
    return 0;
}