#include <stdio.h>
#include <math.h>

typedef long long ll;

ll solve(ll n)
{
    ll result = 1LL, count = 1LL;
    while (result % n) {
        result = (result*10 + 1LL) % n;
        ++count;
    }
    return count;
}

int main(int argc, char const *argv[])
{
    int n;
    while (scanf("%i", &n) == 1) {
        printf("%lli\n", solve(n));
    }
    return 0;
}
