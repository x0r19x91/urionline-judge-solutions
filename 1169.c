#include <stdio.h>

int main(int argc, char const *argv[])
{
    int t, n;
    unsigned long long res;
    scanf("%i", &t);
    do {
        scanf("%i", &n);
        res = (((1ULL << n-1) - 1) << 1) + 1;
        printf("%lli kg\n", res/12000);
    } while(--t);
    return 0;
}
