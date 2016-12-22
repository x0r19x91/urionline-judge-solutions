#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

int main(int argc, char const *argv[])
{
    int n, i, a, b;
    ll *arr;
    ll sum, res, avg;
    while (scanf("%i", &n), n) {
        arr = (ll*) calloc(n, sizeof(ll));
        sum = res = 0;
        for (i = 0; i < n; ++i) {
            scanf("%i.%i", &a, &b);
            sum += arr[i] = a*100+b;
        }
        // avg = (ll)(100.0*sum/n)/100;
        for (i = 0; i < n; ++i) {
            if (arr[i]*n < sum) {
                res += sum - arr[i]*n;
            //    res += avg - arr[i];
            }
        }
        // printf("$%.2lf\n", (1.0*res/n)/100.0);
        printf("$%lf\n", 1.0*res/n);
    }
    return 0;
}
