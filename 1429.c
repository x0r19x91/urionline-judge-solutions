#include <stdio.h>

int fact[] = { 1, 2, 6, 24, 120 };

int main(int argc, char const *argv[])
{
    char buf[8], *iter, *end;
    int result, i, len;
    while (scanf("%s", buf), *buf^0x30) {
        result = i = 0;
        len = __builtin_strlen(buf);
        for (i = len-1; i >= 0; --i) {
            result += (buf[i]-0x30)*fact[len-1-i];
        }
        printf("%i\n", result);
    }
    return 0;
}
