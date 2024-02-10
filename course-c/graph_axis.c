#include <stdio.h>
/**
 * Project:16
 * Author: Palm Civet
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
    canvas_init();
    for (int y = -Y_AXIS; y < Y_AXIS; y++)
    {
        for (int x = -X_AXIS; x < X_AXIS; x++)
        {
            // if (y == parameters[2] * x + parameters[4])
            if (y == -2 * x + 1)
            {
                printf("%d %d\n", x, y);
                // printf("%d %d\n", y, ROW - x);
                // canvas_draw(y + X_AXIS, ROW - x);
                canvas_draw(Y_AXIS - x, y + X_AXIS);
            }
        }
    }
    border_print();
    canvas_print();
    border_print();
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

int canvas_init()
{
    for (int x = 0; x <= ROW; x++)
    {
        for (int y = 0; y < COLUMN; y++)
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
        if (i == COLUMN / 2)
        {
            printf(" +");
        }
        else
        {
            printf(" ─");
        }
    }
    printf(" +");
    printf("\n");
    return 0;
}

/**
 * Test examples:
 * Name Coordinate Parameters
 * 矩形 (1,1)(9,9)(1，9)（9，1）
 * 直线、椭圆形、三角形、矩形、梯形
 */