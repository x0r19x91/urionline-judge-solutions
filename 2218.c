#include <stdio.h>

int main(int argc, char const *argv[])
{
    int t, n;
    long long result;
    scanf("%i", &t);
    do {
        scanf("%i", &n);
        result = 1LL + n;
        result += n*(n-1)/2;
        printf("%lli\n", result);
    } while(--t);
    return 0;
}
