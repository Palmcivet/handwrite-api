#include <stdio.h>
/**
 * Project:16
 * Author: Palm Civet
 */

#define COLUMN 60
#define ROW 39
#define MAX_PARAMETERS 5

char canvas[COLUMN][ROW];
char parameters[MAX_PARAMETERS * 2];

int main()
{
    help_print();
    return 0;
}

int help_print()
{
    printf("========================================\n");
    printf("1)Line:\t\ta\n");
    printf("2)Oval:\t\ta\tb\n");
    printf("3)Triangle:\ta\tb\tc\n");
    printf("4)Rectangle:\ta\tb\n");
    printf("5)Trapezoid:\ta\tb\th\n");
    printf("========================================\n");
    printf("Example:\n");
    printf("Graph>> 5 5 9 4\n");
    printf("Graph>> ");
    gets(parameters);
    return 0;
}

int parameters_check()
{
    if (parameters[1] < '1' || parameters[1] >= '5')
    {
        printf("Invalid Parameter: Graph");
        return 0;
    }

    int i = 1;
    while (parameters[i] != '\0')
    {
        if (parameters[i] <= '0')
        {
            printf("Invalid Parameter: Parameter");
            return 0;
        }
        i++;
    }
    return 0;
}

int canvas_init()
{
    for (int i = 1; i <= ROW; i++)
    {
        for (int j = 1; j <= COLUMN; j++)
        {
            canvas[i][j] = '.';
            //canvas[i][j] = ' ';
        }
    }
}

int canvas_print()
{
    for (int i = 1; i <= ROW; i++)
    {
        for (int j = 0; j <= COLUMN * 2; j += 2)
        {
            //printf(" ");
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

void show()
{
    canvas_init();
    border_print();
    canvas_print();
    border_print();
}
/**
 * Test examples:
 * Name Coordinate Parameters
 * 矩形 (1,1)(9,9)(1，9)（9，1） 
 * 直线、椭圆形、三角形、矩形、梯形
 */