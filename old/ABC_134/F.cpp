/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2019.09.07 17:15:15
 */

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

#define disp(x) cout << #x << ": " << x << endl
#define disp_vec(v)                                                                           \
    cout << #v << ":";                                                                        \
    rep(i, v.size()) cout << " " << v[i];                                                     \
    cout << endl

const int INF = 100000000;
const ll M = 1000000007;
const int dir_4[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int dir_8[8][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

/* ------------------------------------- */

ll dp[60][60][3000];
ll n, k;

int main() {
    scanf("%d%d", &n, &k);

    rep(k1, k + 1) {
        dp[0][0][k1] = 1;
    }

    rep1(i, n) rep(j, i + 1) rep(k1, k + 1) {
        if (k1 - 2 * j < 0)
            continue;

        if (j + 1 > i - 1 && j - 1 < 0) {
            dp[i][j][k1] = (2 * j + 1) * dp[i - 1][j][k1 - 2 * j];
        } else if (j + 1 > i - 1) {
            dp[i][j][k1] =
                (2 * j + 1) * dp[i - 1][j][k1 - 2 * j] + dp[i - 1][j - 1][k1 - 2 * j];
        } else if (j - 1 < 0) {
            dp[i][j][k1] = (2 * j + 1) * dp[i - 1][j][k1 - 2 * j] +
                           (j + 1) * (j + 1) * dp[i - 1][j + 1][k1 - 2 * j];
        } else {
            dp[i][j][k1] = (2 * j + 1) * dp[i - 1][j][k1 - 2 * j] +
                           (j + 1) * (j + 1) * dp[i - 1][j + 1][k1 - 2 * j] +
                           dp[i - 1][j - 1][k1 - 2 * j];
        }
        printf("%lld %lld %lld %lld\n", i, j, k1, dp[i][j][k1]);
    }

    printf("%lld\n", dp[n][0][k]);

    /* --------------------------------- */
    return 0;
}