#include <cstdio>
#include <cmath>

const char *players[] = { "Lucas", "Pedro" };

int main(int argc, char const *argv[])
{
    int t, a, b, f, r = 0;
    double lhs, rhs;
    puts("A competicao terminou empatada!");
    scanf("%i", &t);
    do {
        scanf("%i^%i", &a, &b);
        scanf("%i!", &f);
        lhs = b*log(a);
        rhs = 0.0;
        for (int i = 2; i <= f; ++i) {
            rhs += log(1.0*i);
        }
        printf("Rodada #%i: %s foi o vencedor\n", ++r, players[lhs < rhs]);
    } while(--t);
    return 0;
}
