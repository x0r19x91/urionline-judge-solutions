#include <stdio.h>

typedef long long ll;

ll gcd(ll a, ll b)
{
    return !a ? b : gcd(b%a, a);
}

ll solve(ll n, ll a, ll b)
{
    return n/a + n/b - (n*gcd(a,b))/(a*b);
}

int main(int argc, char const *argv[])
{
    int n, a, b;
    while (scanf("%i %i %i", &n, &a, &b), n && a && b) {
        printf("%lli\n", solve(n, a, b));
    }
    return 0;
}
