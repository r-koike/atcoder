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
const ll M = 1000000000;
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

int n, m;
vector<int> p;
vector<int> pp;

int sup(int x) {
    int l = 0, r = (n + 1) * (n + 1);
    int PP = 0;
    while (r - l >= 1) {
        int i = (l + r) / 2;
        if (pp[i] == x)
            return x;
        else if (pp[i] < x) {
            PP = pp[i];
            l = i + 1;
        } else
            r = i;
    }

    return PP;
}

int main() {
    scanf("%d%d", &n, &m);
    rep(i, n) {
        int j;
        scanf("%d", &j);
        p.pb(j);
    };
    p.pb(0);
    sor(p);

    // p[c] + p[d]の取りうる値を列挙
    rep(c, n + 1) rep(d, n + 1) pp.pb(p[c] + p[d]);
    sor(pp);

    int ret = 0;
    rep(a, n + 1) rep(b, n + 1) {
        int x = m - (p[a] + p[b]);
        if (x < 0)
            continue;
        else if (x == 0) {
            cout << m;
            return 0;
        }
        int P = p[a] + p[b] + sup(x);
        if (ret < P) {
            ret = P;
        }
    }

    cout << ret;
    /* ====================================== */
    cout << endl;
    return 0;
}