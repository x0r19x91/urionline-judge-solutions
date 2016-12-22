#include <stdio.h>

typedef long long ll;

ll solve(ll r, ll n)
{
    int x = 0;
    while (x < 26 && r > n*(1+x)) ++x;
    if (x == 26) x = -1;
    return x;
}

int main(int argc, char const *argv[])
{
    int i;
    ll r, n, temp;
    for (i = 1; scanf("%lli %lli", &r, &n), n; ++i) {
        temp = solve(r, n);
        printf("Case %i: ", i);
        if (temp == -1) {
            puts("impossible");
        } else {
            printf("%lli\n", temp);
        }
    }
    return 0;
}
