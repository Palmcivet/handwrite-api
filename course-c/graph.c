/**
 * Project: 16
 * Author: Palm Civet
 * Date: 2019-6-28
 * Feature:
 *      1. draw a line with y = ax + b
 *      2. draw a graph with coordinates.
 * Github: https://github.com/Palmcivet/Demo/blob/master/Course
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLUMN 68 // X-axis
#define ROW 36	  // Y-axis
#define X_AXIS 34
#define Y_AXIS 18

#define MAX_PARAMETERS 20
#define HELP 0
#define OPERATION 1
#define ADD 2

char canvas[ROW][COLUMN];
char parameters[MAX_PARAMETERS * 2] = {0};

int canvas_init()
{
	for (int y = 0; y <= ROW; y++)
	{
		for (int x = 0; x < COLUMN; x++)
		{
			if ((y == Y_AXIS) || (x == X_AXIS))
			{
				canvas[y][x] = '.';
			}
			else
			{
				canvas[y][x] = ' ';
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
	for (int i = 0; i <= ROW; i++) // Y-axis
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

int wizard(int flag, char *args)
{
	if (flag == HELP)
	{
		printf("Example:\n");
		printf("-------------- Operation ---------------\n");
		printf("0) Exit\n");
		printf("1) Help\n");
		printf("2) Add\n");
		printf("3) Clean\n");
		printf("\n");
		printf("Select an operation:\n");
		printf("Graph>> a\n");
		printf("0) Line\n");
		printf("1) Coordinate\n");
		printf("\n");
		printf("Input type and parameters:\n");
		printf("Graph>> l x1,y1 x2,y2 x3,y3 ...\n");
		printf("---------------------------------------------------------------------\n");
		printf("\n");
		printf("Now select an operation:\n");
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
		printf("=====================================================================\n");
		printf("\n");
		printf("Select an operation:\n");
		printf("Graph>> ");
		scanf("%s", args);
	}
	else if (flag == ADD)
	{
		printf("=============== Arguments ==============\n");
		printf("0) Line\n");
		printf("1) Coordinate\n");
		printf("=====================================================================\n");
		printf("\n");
		printf("Input type and parameters:\n");
		printf("Graph>> ");
		getchar();
		fgets(args, MAX_PARAMETERS, stdin);
	}
	return 0;
}

int gen_line(int a, int b)
{
	for (int y = -Y_AXIS; y <= Y_AXIS; y++)
	{
		for (int x = -X_AXIS; x <= X_AXIS; x++)
		{
			if (y == a * x + b)
			{
				// Can't Modified!!!
				canvas_draw(Y_AXIS - y, X_AXIS + x);
			}
		}
	}
	return 0;
}

int gen_segment(int x_1, int y_1, int x_2, int y_2)
{
	// process the raw data
	// aim: x_1 < x_2 and y_1<y_2
	if ((x_1 > x_2) || (y_1 > y_2))
	{
		int temp = 0;
		// change x
		temp = x_2;
		x_2 = x_1;
		x_1 = temp;
		// change y
		temp = y_2;
		y_2 = y_1;
		y_1 = temp;
	}

	// a don't exist
	if (x_1 == x_2)
	{
		// blow are for the condition that a don't exist
		for (int y = y_1; y <= y_2; y++)
		{
			canvas_draw(Y_AXIS - y, X_AXIS + x_1);
		}
	}
	else
	{
		float a = (float)(y_2 - y_1) / (x_2 - x_1);
		float b = (float)(-x_1) * (y_2 - y_1) / (x_2 - x_1) + y_1;
		for (int y = y_1; y <= y_2; y++)
		{
			for (int x = x_1; x <= x_2; x++)
			{
				if (y == a * x + b)
				{
					canvas_draw(Y_AXIS - y, X_AXIS + x);
				}
			}
		}
	}
	return 0;
}

// Core code
int parameters_handle(char *parameters)
{
	while (strcmp(parameters, "exit") && strcmp(parameters, "quit") && strcmp(&parameters[0], "e") && strcmp(&parameters[0], "q"))
	{
		if (!strcmp(parameters, "help") || !strcmp(&parameters[0], "h"))
		{
			wizard(HELP, parameters);
		}
		else if (!strcmp(parameters, "clean") || !strcmp(&parameters[0], "c"))
		{
			canvas_init();
			printf("Graph cleaned\n");
			wizard(OPERATION, parameters);
		}
		else if (!strcmp(parameters, "add") || !strcmp(&parameters[0], "a"))
		{
			wizard(ADD, parameters);
			if (parameters[0] == 'l') // line
			{
				if ((parameters[2] >= '0' && parameters[2] <= '9') && (parameters[4] >= '0' && parameters[4] <= '9'))
				{
					gen_line((parameters[2] - '0'), (parameters[4] - '0'));
				}
				else
				{
					printf("Invalid Parameter: Missing Arguments!\n\n");
				}
			}
			else if ((parameters[0] == 'c') && (parameters[8] != '\0')) // coordinate
			{
				int i = 4;
				while (parameters[2 * i] != '\0')
				{
					gen_segment(parameters[2 * i - 6] - '0', parameters[2 * i - 4] - '0', parameters[2 * i - 2] - '0', parameters[2 * i] - '0');
					i += 2;
				}
				i -= 2;
				gen_segment(parameters[2 * i - 2] - '0', parameters[2 * i] - '0', parameters[2] - '0', parameters[4] - '0');
			}
			else
			{
				printf("Invalid Parameter: Unvalidated Arguments!\n\n");
				wizard(OPERATION, parameters);
				continue;
			}
			canvas_print();
			wizard(OPERATION, parameters);
		}
		else
		{
			printf("Invalid Input: Unselected Operation!\n\n");
			wizard(OPERATION, parameters);
		}
	}
	return 0;
}

int main()
{
	canvas_init();
	wizard(OPERATION, parameters);
	parameters_handle(parameters);
	return 0;
}
