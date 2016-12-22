#include <stdio.h>

int main(int argc, char const *argv[])
{
    long long arr[21];
    int i;
    arr[0] = 1;
    for (i = 1; i < 21; ++i) {
        arr[i] = arr[i-1]*3;
    }
    scanf("%i", &i);
    printf("%lli\n", arr[i]);
    return 0;
}
