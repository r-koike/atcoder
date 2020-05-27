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
    rep(i, 111) rep(j, 4) rep(k, 4) rep(l, 4) dp[i][j][k][l] = 0LL;
    rep(j, 4) rep(k, 4) rep(l, 4) dp[3][j][k][l] = 1LL;
    dp[3][0][1][2] = 0LL;
    dp[3][1][0][2] = 0LL;
    dp[3][0][2][1] = 0LL;

    if (n == 3) {
        cout << 61 << endl;
        return 0;
    }
    for (int i = 4; i <= n; i++) {
        rep(k1, 4) rep(k2, 4) {
            rep(l, 4) {
                rep(j, 4) {
                    dp[i][k1][k2][l] =
                        (dp[i][k1][k2][l] + dp[i - 1][j][k1][k2]) % M;
                }
            }
        }
        dp[i][0][1][2] = 0LL;
        dp[i][1][3][0] = 0LL;
        dp[i][1][2][1] = 0LL;
        dp[i][1][3][2] -= dp[i - 1][0][1][3];
        dp[i][1][2][2] -= dp[i - 1][0][1][2];
        dp[i][3][1][2] -= dp[i - 1][0][3][1];
        dp[i][1][1][2] -= dp[i - 1][0][1][1];
        dp[i][2][1][2] -= dp[i - 1][0][2][1];
        rep(j, 4) rep(k, 4) rep(l, 4) {
            dp[i][j][k][l] = (dp[i][j][k][l]) % M;
        }
    }

    ll ret = 0LL;
    rep(j, 4) rep(k, 4) rep(l, 4) {
        ret = (ret + dp[n][j][k][l]) % M;
        // ret = ret + dp[n][j][k][l];
    }
    cout << ret;

    /* ====================================== */
    cout << endl;
    return 0;
}