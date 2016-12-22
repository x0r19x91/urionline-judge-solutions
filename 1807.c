#include <stdio.h>
#define MOD 2147483647

typedef long long ll;

ll solve(ll b)
{
    ll a = 3LL, result = 1LL;
    while (b) {
        if (b & 1) {
            result = (result * a) % MOD;
        }
        a = (a*a) % MOD;
        b /= 2;
    }
    if (result < 0) result += MOD;
    return result % MOD;
}

int main(int argc, char const *argv[])
{
    ll n;
    scanf("%lli", &n);
    printf("%lli\n", solve(n));
    return 0;
}
