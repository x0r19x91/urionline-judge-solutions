#include <stdio.h>

int main(int argc, char const *argv[])
{
    long long a, b, c, d;
    scanf("%lli %lli %lli %lli", &a, &b, &c, &d);
    printf("DIFERENCA = %lli\n", a*b-c*d);
    return 0;
}
