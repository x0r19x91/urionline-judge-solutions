#include <stdio.h>

typedef struct fun {
    char* name;
    int val;
    int (*foo) (int, int);
} fun;

int r(int x, int y)
{
    return 9*x*x+y*y;
}

int b(int x, int y)
{
    return 2*x*x+25*y*y;
}

int c(int x, int y)
{
    return y*y*y-100*x;
}

int main(int argc, char const *argv[])
{
    fun p[3] = {"Rafael", 0, r, "Beto", 0, b, "Carlos", 0, c};
    int t, x, y, i, max;
    char* name;
    scanf("%i", &t);
    do {
        max = -2147483648;
        scanf("%i %i", &x, &y);
        for (i = 0; i < 3; ++i) {
            p[i].val = p[i].foo(x, y);
            if (max < p[i].val) {
                max = p[i].val;
                name = p[i].name;
            }
        }
        printf("%s ganhou\n", name);
    } while(--t);
    return 0;
}
