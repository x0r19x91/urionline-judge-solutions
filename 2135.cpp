#include <cstdio>
#include <vector>

int main(int argc, char const *argv[])
{
    int n, i = 0;
    bool flag;
    while (scanf("%i", &n) == 1) {
        std::vector<long long> v(n);
        for (int j = 0; j < n; ++j) {
            scanf("%lli", &v[j]);
        }
        flag = false;
        printf("Instancia %i\n", ++i);
        if (n == 1) {
            printf("%lli\n", v[0]);
        } else {
            for (int j = 1; j < n; ++j) {
                if (v[j] == v[j-1]) {
                    printf("%lli\n", v[j]);
                    flag = true;
                    break;
                }
                v[j] += v[j-1];
            }
            if (! flag) {
                puts("nao achei");
            }
        }
        printf("\n");
    }
    return 0;
}
