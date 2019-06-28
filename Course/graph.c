#include <stdio.h>
/**
 * Project:16
 * Author: Palm Civet
 */

#define COLUMN 64 // X-axis
#define ROW 36    // Y-axis
#define MAX_PARAMETERS 5

#define X_AXIS 32
#define Y_AXIS 18

char canvas[ROW][COLUMN];
char parameters[MAX_PARAMETERS * 2];

int main()
{
    help_print();

    if (parameters[0] < '1' || parameters[0] >= '5')
    {
        printf("Invalid Parameter: Unselected Graph\n\n");
    }
    else
    {
        switch (parameters[1])
        {
        case '0':
            return 0;
        case '1':
            if (!parameters_check(parameters, 2))
            {
                canvas_draw();
            }
            break;
        case '2':
            if (!parameters_check(parameters, 2))
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
        }
        show();
    }
    //help_print(); //TODO: Test
}

int parameters_check(int *para, int para_num)
{
    int i = 1;
    while (i <= para_num)
    {
        if (*(para + 2 * i) == '\0')
        {
            printf("Invalid Parameter: Missing Parameters\n\n");
            return 1;
        }
        else if (*(para + 2 * i) <= '0')
        {
            printf("Invalid Parameter: Unvalidated Parameter\n\n");
            return 1;
        }
        else
        {
            printf("Invalid Input\n\n");
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
    printf("Graph>> 5 5 8 4\n");
    printf("========================================\n");
    printf("\n");
    printf("Graph>> ");
    gets(parameters);
    return 0;
}

void canvas_init()
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
    canvas_init();
    border_print();
    canvas_print();
    border_print();
    printf("\n");
    return 0;
}

/**
 * Test examples:
 * Name Coordinate Parameters
 * 矩形 (1,1)(9,9)(1，9)（9，1） 
 * 直线、椭圆形、三角形、矩形、梯形
 */