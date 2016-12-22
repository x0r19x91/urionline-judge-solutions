#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a, b;
    double c;
    scanf("%i %i %lf", &a, &b, &c);
    printf("NUMBER = %i\nSALARY = U$ %.2lf\n", a, b*c);
    return 0;
}
