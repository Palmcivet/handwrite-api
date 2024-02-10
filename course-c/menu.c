#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct information
{
	int num;
	char name[20];
	struct information *next;
} info;

void print_info(info *chain)
{
	info *p = chain;

	for (p = chain; p != NULL; p = p->next)
	{
		printf("%d %s\n", p->num, p->name);
	}
}

int main()
{
	int tmp_num = 1;
	char tmp_name[50];

	int size = sizeof(info);
	info *tail = NULL, *head = NULL, *p = NULL;

	scanf("%d %s", &tmp_num, tmp_name);
	while (tmp_num != 0)
	{
		p = (info *)malloc(size);
		strcpy(p->name, tmp_name);
		p->num = tmp_num;
		p->next = NULL;

		if (head == NULL)
		{
			head = p;
		}
		else
		{
			tail->next = p;
		}
		tail = p;
		scanf("%d %s", &tmp_num, tmp_name);
	}

	print_info(head);
	return 0;
}