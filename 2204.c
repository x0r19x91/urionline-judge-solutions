#include <stdio.h>

int main(int argc, char const *argv[])
{
    int t;
    char *a, *b;
    scanf("%i", &t);
    do {
        scanf("\n");
        scanf("%m[0-9] %m[0-9]", &a, &b);
        if (! __builtin_strcmp(a, b)) {
            puts(a);
        } else {
            puts("1");
        }
    } while(--t);
    return 0;
}
