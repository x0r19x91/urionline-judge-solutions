#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ll;
char dig[] = "0123456789ABCDEFGHIJKLMNOPQRSTUV";

char* base32(ll n)
{
    int i = 0, j;
    char* str = (char*) calloc(32, 1);
    while (n) {
        str[i++] = dig[n & 31];
        n >>= 5;
    }
    for (j = 0, --i; j < i; --i, ++j) {
        char temp = str[j];
        str[j] = str[i];
        str[i] = temp;
    }
    return str;
}

int main(int argc, char const *argv[])
{
    ll n;
    char* res;
    while (scanf("%llu", &n), n) {
        puts(res = base32(n));
        free(res);
    }
    puts("0");
    return 0;
}
