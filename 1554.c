#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int t, n, i, min_index, min;
    int wx, wy, x, y;
    double temp;
    scanf("%i", &t);
    do {
        min = 2147483647;
        scanf("%i", &n);
        scanf("%i %i", &wx, &wy);
        for (i = 0; i < n; ++i) {
            scanf("%i %i", &x, &y);
            temp = hypot(x-wx, y-wy);
            if (temp < min) {
                min = temp;
                min_index = i;
            }
        }
        printf("%i\n", min_index+1);
    } while(--t);
    return 0;
}
