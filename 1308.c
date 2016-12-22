#include <stdio.h>
#include <math.h>

typedef long long ll;

ll isqrt(ll n)
{
    ll low = 1, high = 1E9, mid, temp;
    for (; low < high;) {
        mid = (low+high)/2;
        temp = mid*mid;
        if (mid == low || temp == n) {
            low = mid;
            break;
        }
        if (low*low <= n && n < temp) {
            high = mid;
        } else if (temp < n && n <= high*high) {
            low = mid;
        } else if (mid*mid == n) {
            low = mid;
            break;
        }
    }
    return low;
}

ll solve(ll n)
{
    // return (isqrt(8*n+1)-1LL)/2LL;
    return ((ll)sqrt(8*n+1)-1)/2LL;
}

int main(int argc, char const *argv[])
{
    int t;
    ll n;
    scanf("%i", &t);
    do {
        scanf("%lli", &n);
        printf("%lli\n", solve(n));
    } while(--t);
    return 0;
}
