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
const ll M = 1000000007;
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

int main() {
    ll n;
    ll dp[111][16];
    cin >> n;
    rep(i, 111) rep(j, 16) dp[i][j] = 0;
    rep(i, 16) dp[3][i] = 4;
    dp[3][2] = 3;
    dp[3][6] = 3;
    dp[3][9] = 3;

    if (n == 3) {
        cout << 61 << endl;
        return 0;
    }

    for (int i = 4; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][4] + dp[i - 1][8] + dp[i - 1][12];
        dp[i][1] = dp[i - 1][0] + dp[i - 1][4] + dp[i - 1][8] + dp[i - 1][12];
        dp[i][2] = dp[i - 1][0] + dp[i - 1][8] + dp[i - 1][12];
        dp[i][3] = dp[i - 1][0] + dp[i - 1][4] + dp[i - 1][8] + dp[i - 1][12];
        dp[i][4] = dp[i - 1][1] + dp[i - 1][5] + dp[i - 1][9] + dp[i - 1][13];
        dp[i][5] = dp[i - 1][1] + dp[i - 1][5] + dp[i - 1][9] + dp[i - 1][13];
        dp[i][6] = dp[i - 1][5] + dp[i - 1][9] + dp[i - 1][13];
        dp[i][7] = dp[i - 1][1] + dp[i - 1][5] + dp[i - 1][9] + dp[i - 1][13];
        dp[i][8] = dp[i - 1][2] + dp[i - 1][6] + dp[i - 1][10] + dp[i - 1][14];
        dp[i][9] = dp[i - 1][6] + dp[i - 1][10] + dp[i - 1][14];
        dp[i][10] = dp[i - 1][2] + dp[i - 1][6] + dp[i - 1][10] + dp[i - 1][14];
        dp[i][11] = dp[i - 1][2] + dp[i - 1][6] + dp[i - 1][10] + dp[i - 1][14];
        dp[i][12] = dp[i - 1][3] + dp[i - 1][7] + dp[i - 1][11] + dp[i - 1][15];
        dp[i][13] = dp[i - 1][3] + dp[i - 1][7] + dp[i - 1][11] + dp[i - 1][15];
        dp[i][14] = dp[i - 1][3] + dp[i - 1][7] + dp[i - 1][11] + dp[i - 1][15];
        dp[i][15] = dp[i - 1][3] + dp[i - 1][7] + dp[i - 1][11] + dp[i - 1][15];
        rep(j, 16) {
            dp[i][j] = dp[i][j] % M;
        }
    }

    ll ret = 0;
    rep(i, 16) {
        ret = (ret + dp[n][i]) % M;
    }
    cout << ret;

    /* ====================================== */
    cout << endl;
    return 0;
}