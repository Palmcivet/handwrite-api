/**
 * Project: 16
 * Author: Palm Civet
 * Date: 2019-6-28
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

void CirclePoints(int y, int x)
{
	// CirclePoints(Y_AXIS - y,  + x);
	canvas_draw(Y_AXIS + x, X_AXIS + y);
	canvas_draw(Y_AXIS + x, X_AXIS - y);
	canvas_draw(Y_AXIS - x, X_AXIS + y);
	canvas_draw(Y_AXIS - x, X_AXIS - y);
	canvas_draw(Y_AXIS + y, X_AXIS + x);
	canvas_draw(Y_AXIS + y, X_AXIS - x);
	canvas_draw(Y_AXIS - y, X_AXIS + x);
	canvas_draw(Y_AXIS - y, X_AXIS - x);
}

char *substring(char *ch, int pos, int length)
{
	char *pch = ch;
	char *subch = (char *)calloc(sizeof(char), length + 1);
	int i;
	pch = pch + pos;
	for (i = 0; i < length; i++)
	{
		subch[i] = *(pch++);
	}
	subch[length] = '\0';
	return subch;
}

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
		printf("2) Oval\n");
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
		printf("2) Oval\n");
		printf("=====================================================================\n");
		printf("\n");
		printf("Input type and parameters:\n");
		printf("c 1,2 5,8 4,1\n");
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
			// Can't Modified!!!
			if (y == a * x + b)
				canvas_draw(Y_AXIS - y, X_AXIS + x);
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
					canvas_draw(Y_AXIS - y, X_AXIS + x);
			}
		}
	}
	return 0;
}

void gen_circle(int r)
{
	// ugly circle
	// 中点画圆法
	int x, y;
	double d;

	x = 0;
	y = r;
	d = 1.25 - r;
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
		// canvas_draw(Y_AXIS - y, X_AXIS + x);
		CirclePoints(x, y);
		// CirclePoints(x, y);
	}
}

int gen_oval(float a, float b)
{
	for (float y = -Y_AXIS; y <= Y_AXIS; y += 1)
	// for (int y = -Y_AXIS; y <= Y_AXIS; y++)
	{
		for (float x = -X_AXIS; x <= X_AXIS; x += 1)
		// for (int x = -X_AXIS; x <= X_AXIS; x++)
		{
			// if (y * y / a / a + x * x / b / b == 1)
			if (y * y + x * x == a * b)
			{
				printf("%f %f\n", y, x);
				// printf("%d*%d/a/a + %d*%d/b/b\n", y, y, x, x);
				canvas_draw(Y_AXIS - (int)y, X_AXIS + (int)x);
				// canvas_draw(Y_AXIS - y, X_AXIS + x);
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
			memset(parameters, ' ', MAX_PARAMETERS);
			wizard(ADD, parameters);
			if (parameters[0] == 'l') // line
			{
				if ((parameters[2] >= '0' && parameters[2] <= '9') && (parameters[4] >= '0' && parameters[4] <= '9'))
				{
					gen_line((parameters[2] - '0'), (parameters[4] - '0'));
					canvas_print();
				}
				else
				{
					printf("Invalid Parameter: Missing Arguments!\n\n");
				}
			}
			else if (parameters[0] == 'c') // coordinate
			{
				int length = 0;
				for (int valid = 0; parameters[2 * valid] != '\0'; valid++)
				{
					if (parameters[2 * valid] < '0' && parameters[2 * valid] >= '9')
					{
						break;
					}
					else
					{
						length = valid;
					}
				}
				printf("%d\n", length);
				for (int i = 4; i <= length; i += 2)
				{
					gen_segment(parameters[2 * i - 6] - '0', parameters[2 * i - 4] - '0', parameters[2 * i - 2] - '0', parameters[2 * i] - '0');
				}
				gen_segment(parameters[2 * length - 2] - '0', parameters[2 * length] - '0', parameters[2] - '0', parameters[4] - '0');
				canvas_print();
			}
			else if (parameters[0] == 'o')
			{
				/**
				 * o -34 -67 => 3
				 * o 098 hjl
				 */
				// if (atol(substring(parameters, 2, 3)) != 0.0 && 0.0 != atol(substring(parameters, 6, 3)))
				//{
				//	gen_oval(atof(substring(parameters, 2, 3)), atof(substring(parameters, 6, 3)));
				//	canvas_print();
				// }

				if (atol(substring(parameters, 2, 2)) != 0.0)
				{
					gen_circle(atof(substring(parameters, 2, 2)));
					canvas_print();
				}
			}
			else
			{
				printf("Invalid Parameter: Unvalidated Arguments!\n\n");
				wizard(OPERATION, parameters);
				continue;
			}
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
