#include <fstream>
#include <cstdio>

typedef long long ll;

class Matrix {
    ll a, b, c, d, mod;
public:
    Matrix(ll x, ll y, ll z, ll w, ll m) : a(x), b(y), c(z), d(w), mod(m) {}
    Matrix(const Matrix& m) : a(m.a), b(m.b), c(m.c), d(m.d), mod(m.mod) {}
    Matrix operator=(Matrix o) {
        a = o.a;
        b = o.b;
        c = o.c;
        d = o.d;
        mod = o.mod;
        return *this;
    }
    bool operator==(Matrix o) {
        return a == o.a && b == o.b && c == o.c && d == o.d;
    }
    Matrix operator+(Matrix o) {
        Matrix m(a+o.a, b+o.b, c+o.c, d+o.d, o.mod);
        return m;
    }
    Matrix operator*(Matrix o) {
        Matrix m((a*o.a+b*o.c) % mod, (a*o.b+b*o.d) % mod, (c*o.a+d*o.c) % mod, (c*o.b+d*o.d) % mod, mod);
        return m;
    }
    Matrix operator%(ll o) {
        Matrix m(a % o, b % o, c % o, d % o, o);
        return m;
    }
    static Matrix fast_pow(Matrix a, ll b, ll mod) {
        Matrix res(1, 0, 0, 1, mod);
        while (b) {
            if (b & 1) {
                res = (res*a);// % mod;
            }
            a = (a*a);// % mod;
            b /= 2;
        }
        return res;
    }
public:
    friend ll h(ll index, ll mod);
    friend std::ostream& operator<<(std::ostream& strm, Matrix m) {
        strm << '[' << m.a << ' ' << m.b << ' ' << m.c << ' ' << m.d << ']';
        return strm;
    }
};

ll h(ll index, ll mod) {
    ll result;
    if (!index) {
        result = -1;
    } else {
        ll m = ((index & 1) + (index/2)) << 1;
        ll n = (m-2)>>1;
        Matrix init(-2, 1, 1, -1, mod);
        Matrix exponent(2, -1, -1, 1, mod);
        Matrix temp(init);
        temp = temp * Matrix::fast_pow(exponent, n, mod);
        if (index & 1) {
            result = temp.b;
        } else {
            result = temp.a;
        }
    }
    return result % mod;
}

ll solve(ll index, ll mod) {
    ll res = (2*h(index, mod)) % mod;
    if (~index & 1) {
        res = (mod-res) % mod;
        // res = (-res) % mod;
    }
    return (res-1+mod) % mod;
    // return (res-1) % mod;
}

int main(int argc, char const *argv[])
{
    ll n, b, test = 0;
    while (scanf("%lli %lli", &n, &b), b) {
        printf("Case %lli: %lli %lli %lli\n", ++test, n, b, solve(n, b));
    }
    return 0;
}
