#include <stdio.h>

long double cf(int iter)
{
    long double res = 1.0;
    while (iter--) {
        res = (2 + res) / (1 + res);
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%i", &n);
    printf("%.10Lf\n", cf(n));
    return 0;
}
