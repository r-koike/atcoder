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
typedef pair<ll, ll> P;
typedef pair<ll, P> P1;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define rep(i, x) for (ll i = 0; i < x; i++)
#define rep1(i, x) for (ll i = 1; i <= x; i++)
#define rrep(i, x) for (ll i = x - 1; i >= 0; i--)
#define rrep1(i, x) for (ll i = x; i > 0; i--)
#define sor(v) sort(v.begin(), v.end())
#define rev(s) reverse(s.begin(), s.end())
#define lb(vec, a) lower_bound(vec.begin(), vec.end(), a)
#define ub(vec, a) upper_bound(vec.begin(), vec.end(), a)
#define uniq(vec) vec.erase(unique(vec.begin(), vec.end()), vec.end())
#define mp1(a, b, c) P1(a, P(b, c))

const ll INF = 100000000;
const ll M = 1000000007LL;
const ll dir_4[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const ll dir_8[8][2] = {{1, 0},  {1, 1},   {0, 1},  {-1, 1},
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

ll dp[111][4][4][4];

int main() {
    ll n;
    cin >> n;

    dp[0][3][3][3] = 1;
    rep(i, n) rep(j, 4) rep(k, 4) rep(l, 4) rep(m, 4) {
        if (k == 0 && l == 1 && m == 2)
            continue;
        if (k == 1 && l == 0 && m == 2)
            continue;
        if (k == 0 && l == 2 && m == 1)
            continue;
        if (j == 0 && l == 1 && m == 2)
            continue;
        if (j == 0 && k == 1 && m == 2)
            continue;
        dp[i + 1][k][l][m] = (dp[i + 1][k][l][m] + dp[i][j][k][l]) % M;
    }

    int ret = 0;
    rep(j, 4) rep(k, 4) rep(l, 4) {
        ret = (ret + dp[n][j][k][l]) % M;
    }
    cout << ret;

    /* ====================================== */
    cout << endl;
    return 0;
}