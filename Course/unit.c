#include <stdio.h>
#include <string.h>
int main()
{
    printf("=============== Example =================\n");

    char parameters[20];
    fgets(parameters, 20, stdin);
    printf("%s\n", parameters);
    printf("%d %d\n", '-' - '0', ' ' - '0');
    return 0;
}