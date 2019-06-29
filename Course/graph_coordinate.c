/**
 * Project:16
 * Author: Palm Civet
 * Date: 2019-6-28
 * Github: https://github.com/Palmcivet/Demo/blob/master/Course
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COLUMN 68 // X-axis
#define ROW 36    // Y-axis
#define X_AXIS 34
#define Y_AXIS 18

#define MAX_PARAMETERS 20
#define HELP 0
#define OPERATION 1
#define ADD 2

char canvas[ROW][COLUMN];
char parameters[MAX_PARAMETERS * 2];

int main()
{
    canvas_init();
    strcpy(parameters, "help");
    parameters_handle(parameters);
    return 0;
}

int wizard(int flag, char *args)
{
    if (flag == HELP)
    {
        printf("=============== Example ================\n");
        printf("-------------- Operation ---------------\n");
        printf("0) Exit\n");
        printf("1) Help\n");
        printf("2) Add\n");
        printf("3) Clean\n");
        printf("----------------------------------------\n");
        printf("\n");
        printf("Select an operation:\n");
        printf("Graph>> a\n");
        printf("\n");
        printf("--------------- Arguments --------------\n");
        printf("0) Line\n");
        printf("1) Coordinate\n");
        printf("----------------------------------------\n");
        printf("\n");
        printf("Input type and parameters:\n");
        printf("Graph>> l x1,y1 x2,y2 x3,y3 ...\n");
        printf("========================================\n");
        printf("Graph>> ");
        scanf("%s", args);
    }
    else if (flag == OPERATION)
    {
        printf("\n");
        printf("=============== Operation ==============\n");
        printf("0) Exit\n");
        printf("1) Help\n");
        printf("2) Add\n");
        printf("3) Clean\n");
        printf("========================================\n");
        printf("\n");
        printf("Select an operation:\n");
        printf("Graph>> ");
        //scanf("%s", parameters);
        scanf("%s", args);
    }
    else if (flag == ADD)
    {
        printf("=============== Arguments ==============\n");
        printf("0) Line\n");
        printf("1) Coordinate\n");
        printf("========================================\n");
        printf("\n");
        printf("Input type and parameters:\n");
        printf("Graph>> ");
        //fgets(parameters, MAX_PARAMETERS, stdin);
        fgets(args, MAX_PARAMETERS, stdin);
    }
    return 0;
}

// Core code
int parameters_handle(int *parameters)
{
    if (!strcmp(parameters, "exit") || !strcmp(&parameters[0], "e"))
    {
        printf("thanks");
        exit(0);
        //return 0;
    }
    else if (!strcmp(parameters, "help") || !strcmp(&parameters[0], "h"))
    {
        wizard(HELP, parameters);
    }
    else if (!strcmp(*parameters, "clean") || !strcmp(&parameters[0], "c"))
    {
        canvas_init();
    }
    else if (!strcmp(parameters, "add") || !strcmp(&parameters[0], "a"))
    {
        wizard(ADD, parameters);
        if (!strcmp(&parameters[0], "l")) // line
        {
            if (parameters[2] == '\0')
            {
                return 0;
            }
            gen_line((parameters[2]), parameters[4]);
        }
        else if (!strcmp(&parameters[0], "c")) // coordinate
        {
            int i = 4;
            while (parameters[2 * i] != '\0')
            {
                //gen_segment(parameters[2 * i], parameters[2 * i + 2], parameters[2 * 1 + 4], parameters[2 * i + 8]);
                gen_segment(parameters[2 * i - 6], parameters[2 * i - 4], parameters[2 * 1 - 2], parameters[2 * i]);
                i += 2;
            }
            gen_segment(parameters[2 * i], parameters[2 * i], parameters[2], parameters[4]);
        }
        else
        {
            printf("Invalid Parameter: Unvalidated Parameter!\n\n");
            return 0;
        }
        canvas_print();
    }
    else
    {
        printf("Invalid Input: Undelected Operation!\n\n");
    }
    wizard(OPERATION, parameters);
}

int gen_line(int a, int b)
{
    //for (int y = -Y_AXIS; y <= Y_AXIS; y++)
    for (int y = -Y_AXIS; y <= Y_AXIS; y++)
    {
        for (int x = -X_AXIS; x <= X_AXIS; x++)
        {
            if (y == a * x + b)
            {
                printf("%d %d\n", x, y); //TODO: cancel comment
                canvas_draw(Y_AXIS - x, X_AXIS + y);
            }
        }
    }
    return 0;
}

int gen_segment(int x_1, int y_1, int x_2, int y_2)
{
    int a = (y_1 - y_2) / (x_1 - x_2);
    int b = (-x_1) * (y_1 - y_2) / (x_1 - x_2) + y_1;
    //for (int y = -Y_AXIS; y <= Y_AXIS; y++)
    for (int y = -x_1; y <= y_2; (y_1 > y_2) ? y-- : y++)
    {
        for (int x = -x_1; x <= x_2; (x_1 > x_2) ? x-- : x++)
        {
            if (y == a * x + b)
            {
                printf("%d %d\n", x, y); //TODO: cancel comment
                canvas_draw(Y_AXIS - x, X_AXIS + y);
            }
        }
    }
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
    // Top border
    printf(" +");
    for (int i = 1; i < COLUMN; i++)
    {
        printf(" ─");
    }
    printf(" +");
    printf("\n");

    // Canvas
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

    // Buttom border
    printf(" +");
    for (int i = 1; i < COLUMN; i++)
    {
        printf(" ─");
    }
    printf(" +");
    printf("\n");
    return 0;
}
