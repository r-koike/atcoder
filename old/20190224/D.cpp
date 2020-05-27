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

const ll INF = 1000000000000;
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

int main() {
    int a, b, q;
    vector<ll> s;
    vector<ll> t;
    vector<ll> xs;

    cin >> a >> b >> q;
    rep(i, a) {
        ll ca;
        scanf("%lld", &ca);
        s.pb(ca);
    }
    rep(i, b) {
        ll cb;
        scanf("%lld", &cb);
        t.pb(cb);
    }
    rep(i, q) {
        ll cq;
        scanf("%lld", &cq);
        xs.pb(cq);
    }
    s.pb(INF);
    t.pb(INF);
    sor(s);
    sor(t);

    rep(i, q) {
        ll x = xs[i];
        auto its = lb(s, x);
        auto itt = lb(t, x);
        ll dirs0, dirt0, dirs1, dirt1;

        dirs1 = *its - x;
        if (its - s.begin() == 0) {
            dirs0 = INF;
        } else {
            dirs0 = x - *(its - 1);
        }

        dirt1 = *itt - x;
        if (itt - t.begin() == 0) {
            dirt0 = INF;
        } else {
            dirt0 = x - *(itt - 1);
        }

        ll ret0, ret1, ret2, ret3;
        ret0 = max(dirs0, dirt0);
        ret1 = max(dirs1, dirt1);
        ret2 = (dirs0 > dirt1) ? dirt1 * 2 + dirs0 : dirs0 * 2 + dirt1;
        ret3 = (dirt0 > dirs1) ? dirs1 * 2 + dirt0 : dirt0 * 2 + dirs1;

        cout << min(min(ret0, ret1), min(ret2, ret3)) << endl;
    }

    /* ====================================== */
    return 0;
}