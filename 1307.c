#include <stdlib.h>
#include <stdio.h>

typedef long long ll;
char *result[] = { "Love is not all you need!", "All you need is love!" };

ll gcd(ll a, ll b)
{
    if (! a) {
        return b;
    } else if (~a&1 && ~b&1) {
        return 2LL * gcd(a/2, b/2);
    } else if (~a & 1) {
        return gcd(a/2, b);
    } else if (~b & 1) {
        return gcd(a, b/2);
    } else {
        return gcd(__builtin_abs(a-b), a);
    }
}

int solve(const char* a, const char* b)
{
    ll ia = strtoll(a, NULL, 2);
    ll ib = strtoll(b, NULL, 2);
    return gcd(ia, ib) > 1;
}

int main(int argc, char const *argv[])
{
    int n, i;
    char A[32], B[32];
    scanf("%i", &n);
    for (i = 1; i <= n; ++i) {
        scanf("\n%s %s", A, B);
        printf("Pair #%i: %s\n", i, result[solve(A, B)]);
    }
    return 0;
}
