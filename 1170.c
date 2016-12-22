#include <math.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int t;
    double n;
    scanf("%i", &t);
    do {
        scanf("%lf", &n);
        printf("%lli dias\n", (long long)ceil(log2(n)));
    } while(--t);
    return 0;
}
