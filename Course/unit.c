#include <stdio.h>
#include <string.h>
int main()
{
    printf("=============== Example =================\n");

    char parameters[20];
    fgets(parameters, 20, stdin);
    printf("%s", parameters);
    return 0;
}