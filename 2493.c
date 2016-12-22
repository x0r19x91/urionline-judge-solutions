#include <stdio_ext.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define IS_DIGIT(i) ((i) >= 0x30 && (i) <= 0x39)

typedef struct player_t {
    // char name[64];
    char* name;
    int expr_index;
    char op;
    char passed;
} PLAYER, *PPLAYER;

int compare_player(const void* player1, const void* player2)
{
    PPLAYER p1 = (PPLAYER) player1;
    PPLAYER p2 = (PPLAYER) player2;
    return __builtin_strcmp(p1->name, p2->name);
}

char guess_operator(const char* str)
{
    char* expr = __builtin_strdup(str);
    char *ptr = expr;
    int num1, num2, res, s1, s2;
    if (IS_DIGIT(*ptr) || *ptr == '+' || *ptr == '-') {
        num1 = 0;
        s1 = 1;
        if (*ptr == '-') {
            s1 = -1;
            ++ptr;
        } else if (*ptr == '+') {
            ++ptr;
        }
        while (IS_DIGIT(*ptr)) {
            num1 = 10*num1 + *ptr++ - 0x30;
        }
    }
    num1 *= s1;
    /* *ptr is a space */
    ++ptr;
    if (IS_DIGIT(*ptr)) {
        num2 = 0;
        s2 = 1;
        if (*ptr == '-') {
            s2 = -1;
            ++ptr;
        } else if (*ptr == '+') {
            ++ptr;
        }
        while (IS_DIGIT(*ptr)) {
            num2 = 10*num2 + *ptr++ - 0x30;
        }
    }
    num2 *= s2;
    /* *ptr is '=' */
    ++ptr;
    if (IS_DIGIT(*ptr)) {
        res = 0;
        while (IS_DIGIT(*ptr)) {
            res = 10*res + *ptr++ - 0x30;
        }
    }
    if (num1 + num2 == res) {
        return '+';
    } else if (num1 - num2 == res) {
        return '-';
    } else if (num1 * num2 == res) {
        return '*';
    } else {
        return 'I'; /* Impossible with +, -, * */
    }
}


int main(int argc, char const *argv[])
{
    int n, i;
    size_t temp;
    int p;
    char **expr;
    PPLAYER players;
    while (scanf("%i", &n) == 1) {
        expr = (char**) calloc(n, sizeof(char*));
        players = (PPLAYER) calloc(n, sizeof(PLAYER));
        for (i = 0; i < n; ++i) {
            // temp = 0;
            // expr[i] = (char*) calloc(32, sizeof(char*));
            scanf("\n%m[^\n]", expr+i);
        }
        // __fpurge(stdin);
        for (i = 0; i < n; ++i) {
            scanf("%ms %i %c", &players[i].name, &players[i].expr_index, &players[i].op);
        }
        p = 0;
        for (i = 0; i < n; ++i) {
            players[i].passed = players[i].op == guess_operator(expr[players[i].expr_index-1]);
            p += players[i].passed == 0;
        }
        qsort(players, n, sizeof(PLAYER), compare_player);
        if (p == n) {
            printf("None Shall Pass!");
        } else {
            for (i = 0; i < n; ++i) {
                if (! players[i].passed) {
                    printf("%s ", players[i].name);
                }
            }
        }
        free(expr);
        printf("\n");
        free(players);
    }
    return 0;
}
