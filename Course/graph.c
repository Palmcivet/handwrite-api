#include <stdio.h>
/**
 * Project:16
 * Author: Palm Civet
 * Date: 2019-6-28
 */

#define COLUMN 68 // X-axis
#define ROW 36    // Y-axis
#define MAX_PARAMETERS 5

#define X_AXIS 34
#define Y_AXIS 18

char canvas[ROW][COLUMN];
char parameters[MAX_PARAMETERS * 2];

int main()
{
    help_print();
    canvas_init();

    switch (parameters[0])
    {
    case '0':
        return 0;
    case '1':
        if (!parameters_check(parameters, 2))
        {
            for (int y = -Y_AXIS; y <= Y_AXIS; y++)
            {
                for (int x = -X_AXIS; x <= X_AXIS; x++)
                {
                    if (y == (int)(parameters[2] - '0') * x + (int)(parameters[4] - '0'))
                    {
                        //printf("%d %d\n", x, y);
                        //canvas_draw(y - Y_AXIS, X_AXIS + x);
                        canvas_draw(Y_AXIS - x, X_AXIS + y);
                    }
                }
            }
        }
        break;
    case '2':
        if (!parameters_check(parameters, 2))
        {
            int a = (int)(parameters[2] - '0');
            int b = (int)(parameters[4] - '0');
            for (int y = -Y_AXIS; y <= Y_AXIS; y++)
            {
                for (int x = -X_AXIS; x <= X_AXIS; x++)
                {
                    if (x * x + y * y == 49)
                    //if (b * b * x * x + a * a * y * y == a * a * b * b)
                    {
                        printf("%d %d\n", x, y); //TODO: cancel comment
                        canvas_draw(Y_AXIS - x, X_AXIS + y);
                    }
                }
            }
        }
        break;
    case '3':
        if (!parameters_check(parameters, 3))
            break;
    case '4':
        if (!parameters_check(parameters, 2))
            break;
    case '5':
        if (!parameters_check(parameters, 3))
            break;
    default:
        printf("Invalid Parameter: Unselected Graph\n\n");
        break;
    }
    show();
    //help_print(); //TODO: cancel comment
}

int parameters_check(int *para, int para_num) //!!! Can't Modify
{
    int i = 1;
    while (i <= para_num)
    {
        if (*(parameters + 2 * i) == '\0')
        {
            printf("Invalid Parameter: Missing Parameters\n\n");
            return 1;
        }
        else if (*(parameters + 2 * i) <= '0')
        {
            printf("Invalid Parameter: Unvalidated Parameter\n\n");
            return 1;
        }
        i++;
    }
    return 0;
}

int help_print()
{
    printf("========================================\n");
    printf("0) Exit\n");
    printf("1) Line:\tm\tn\n");
    printf("2) Oval:\ta\tb\n");
    printf("3) Triangle:\ta\tb\tc\n");
    printf("4) Rectangle:\ta\tb\n");
    printf("5) Trapezoid:\ta\tb\th\n");
    printf("\n");
    printf("Example:\n");
    printf("Graph>> 5 0,5 0,8 4,5 2,8\n");
    printf("========================================\n");
    printf("\n");
    printf("Graph>> ");
    gets(parameters);
    return 0;
}

int canvas_init()
{
    for (int x = 0; x < ROW; x++)
    {
        for (int y = 1; y < COLUMN; y++)
        {
            if ((x == Y_AXIS) || (y == X_AXIS))
            {
                canvas[x][y] = '.';
            }
            else
            {
                canvas[x][y] = ' ';
            }
        }
    }
    return 0;
}

int canvas_draw(int x, int y)
{
    if (canvas[x][y] == ' ')
    {
        canvas[x][y] = '.';
    }
    return 0;
}

int canvas_print()
{
    for (int i = 0; i < ROW; i++) // Y-axis
    {
        for (int j = 0; j <= COLUMN * 2; j += 2) // X-axis
        {
            if (j == 0 || j == COLUMN * 2)
            {
                printf(" |");
            }
            else if ((i == Y_AXIS + 1) && (j == COLUMN + 2))
            {
                printf(" o");
            }
            else
            {
                printf(" %c", canvas[i][j / 2]);
            }
        }
        printf("\n");
    }
    return 0;
}

int border_print()
{
    printf(" +");
    for (int i = 1; i < COLUMN; i++)
    {
        printf(" ─");
    }
    printf(" +");
    printf("\n");
    return 0;
}

int show()
{
    border_print();
    canvas_print();
    border_print();
    return 0;
}

/**
 * Test examples:
 * Name Coordinate Parameters
 * 矩形 (1,1)(9,9)(1，9)（9，1） 
 * 直线、椭圆形、三角形、矩形、梯形
 */