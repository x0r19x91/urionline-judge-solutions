#include <stdio.h>

typedef long double ld;
typedef long long ll;

ll proxy(int n)
{
    ll res = (n*(n-1LL)*(2*n-1LL))/6LL;
    int m = n/2;
    res += m*n*n + (2LL*(m+1)*(2*m-3*n+1)*m)/3LL;
    return res;
}

double solve(int n, double p)
{
    ll res = n*n;
    res = (res*(res-1LL)*(res-2LL)*(res-3LL))/24LL;
    res /= proxy(n);
    return res*(p/100.0);
}

ll proxy2(int n, int side)
{
    ll res = 1LL, temp = n - side;
    res = temp*temp + (temp-side)*(temp-side);
    return res;
}

ll nCr(int n, int r)
{
    ll res = 1LL;
    int i;
    for (i = 1; i <= r; ++i) {
        res = (res * n--)/i;
    }
    return res;
}

double solve2(int n, double p)
{
    ll res = 1LL*n*n;
    ll temp = 0;
    int i;
    res = (res*(res-1)*(res-2)*(res-3))/24LL;
    //for (i = 1; i < 2; ++i) {
    //    temp += nCr(n*n, 4*i);
    //}
    temp = nCr(n*n, 4);
    temp /= proxy(n);
    return temp * .01 * p;
}

int main(int argc, char const *argv[])
{
    int i;
    double f;
    while (scanf("%i %lf", &i, &f), i) {
        printf("%.2lf\n", solve2(i, f));
    }
    return 0;
}
