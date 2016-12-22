#include <math.h>
#include <stdio.h>

typedef long long ll;

ll flp(ll n)
{
    n = n | n >> 1;
    n = n | n >> 2;
    n = n | n >> 4;
    n = n | n >> 8;
    n = n | n >> 16;
    n = n | n >> 32;
    return n - (n >> 1);
}

ll ilg(ll n)
{
    ll tz = __builtin_ctzll(n);
    return tz;
}

ll count (ll n)
{
    ll i = 0, end, b, cnt = 0;
    for (; n; ++i) {
        end = flp(n);
        b = ilg(end);
        cnt += b * (ll)pow(2, b-1);
        n = n - end;
        cnt += n+1;
    }
    return cnt;
}

ll solve(ll a, ll b)
{
    return count(b) - count(a-1);
}

int main(int argc, char const *argv[])
{
    ll a, b;
    while (scanf("%lli %lli", &a, &b) == 2) {
        printf("%lli\n", solve(a, b));
    }
    return 0;
}
