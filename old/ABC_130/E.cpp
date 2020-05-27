/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2019.06.16 21:23:52
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

ll n, m;
ll s[2010], t[2010];
ll dp[2010][2010];

int main() {
    scanf("%lld%lld", &n, &m);
    rep(i, n) {
        scanf("%lld", &s[i]);
    }
    rep(i, m) {
        scanf("%lld", &t[i]);
    }

    dp[0][0] = 1LL;
    rep(i, n + 1) {
        dp[i][0] = 1;
    }
    rep(j, m + 1) {
        dp[0][j] = 1;
    }
    rrep1(i, n) rep1(j, m) {
        if (s[i - 1] == t[j - 1]) {
            dp[i][j] = (dp[i - 1][j - 1] * 2) % M;
        } else {
            dp[i][j]
        }
    }

    /* --------------------------------- */
    return 0;
}