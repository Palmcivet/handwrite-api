#include <stdio.h>
#include <string.h>
int main()
{
    printf("=============== Example =================\n");

    char parameters[20];
    scanf("%s", parameters);
    if (!strcmp(parameters, "add") || !strcmp(&parameters[0], "a"))
        printf("ok");
    return 0;
}