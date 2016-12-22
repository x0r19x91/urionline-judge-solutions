#include <stdio.h>
#include <math.h>

void solve(int a, int b, int c, double *circum, double *tri, double *inc)
{
    double s = (a+b+c)/2.0, temp;
    *tri = sqrt(s*(s-a)*(s-b)*(s-c));
    temp = (a*b*c)/(4**tri);
    *circum = M_PI * temp * temp;
    *inc =( M_PI*(s-a)*(s-b)*(s-c))/s;
    *circum -= *tri;
    *tri -= *inc;
}

int main(int argc, char const *argv[])
{
    int a, b, c;
    double f_sun, f_vio, f_red;
    while (scanf("%i %i %i", &a, &b, &c) == 3) {
        solve(a, b, c, &f_sun, &f_vio, &f_red);
        printf("%.4lf %.4lf %.4lf\n", f_sun, f_vio, f_red);
    }
    return 0;
}
