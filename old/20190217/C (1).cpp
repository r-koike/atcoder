#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef pair<int, P> P1;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define rep(i, x) for (int i = 0; i < x; i++)
#define rep1(i, x) for (int i = 1; i <= x; i++)
#define rrep(i, x) for (int i = x - 1; i >= 0; i--)
#define rrep1(i, x) for (int i = x; i > 0; i--)
#define sor(v) sort(v.begin(), v.end())
#define rev(s) reverse(s.begin(), s.end())
#define lb(vec, a) lower_bound(vec.begin(), vec.end(), a)
#define ub(vec, a) upper_bound(vec.begin(), vec.end(), a)
#define uniq(vec) vec.erase(unique(vec.begin(), vec.end()), vec.end())
#define mp1(a, b, c) P1(a, P(b, c))

const int INF = 1000000000;
const ll M = 1000000007;
const int dir_4[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int dir_8[8][2] = {{1, 0},  {1, 1},   {0, 1},  {-1, 1},
                         {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

/*----------------------------------------------/
/- char         : %c  | char *       : %s  | short        : %hd
/- int          : %d  | long         : %ld | long long    : %lld
/- unsigned short:%hu | unsigned int : %u  | unsigned long: %lu
/- u_long long  : %llu| (octal)      : %o  | (hexadecimal): %x
/- float        : %f  | double       : %lf |
/----------------------------------------------*/

/*----------------------------------------------/
/- INT_MAX, LONG_MAX   : 1<<15 = 2.1*pow(10, 9)       (= 2147483647)
/- UINT_MAX, ULONG_MAX : 1<<16 = 4.2*pow(10, 9)       (= 4294967295)
/- LLONG_MAX           : 1<<63 = 9.2*pow(10, 18)      (= 9223372036854775807)
/- ULLONG_MAX          : 1<<64 = 1.8*pow(10, 19)      (= 18446744073709551615)
/----------------------------------------------*/

int main() {
    static ll n;
    static ll t[100010];
    static ll a[100010];
    static ll h[100010];
    static ll H[100010];
    scanf("%lld", &n);
    rep(i, n) scanf("%lld", &t[i]);
    rep(i, n) scanf("%lld", &a[i]);

    rep(i, 100010) {
        h[i] = -1;
        H[i] = 1000000000;
    }
    int x = -1;
    rep(i, n) {
        if (x < t[i]) {
            h[i] = t[i];
            x = t[i];
        } else
            H[i] = t[i];
    }
    x = -1;
    rrep(i, n) {
        if (x < a[i]) {
            if (h[i] != -1 && h[i] != a[i]) {
                puts("0");
                return 0;
            }
            h[i] = a[i];
            x = a[i];
        } else
            H[i] = min(H[i], a[i]);
    }

    ll ret = 1;
    rep(i, n) {
        if (h[i] > H[i]) {
            puts("0");
            return 0;
        }
        if (h[i] == -1) {
            ret *= H[i];
            ret %= M;
        }
    }
    cout << ret;

    /* ====================================== */
    cout << endl;
    return 0;
}