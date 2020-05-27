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

const ll INF = 10000000000000;
const int M = 100000000;
const int dir_4[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int dir_8[8][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

/* ------------------------------------- */
ll dp[400][400];
ll n, m, k, a[400];

int main() {
    scanf("%lld%lld%lld", &n, &m, &k);
    a[0] = 0LL;
    rep1(i, n) scanf("%lld", &a[i]);

    if (m > n) {
        printf("%d\n", -1);
        return 0;
    }
    if ((n + k - 1LL) / k > m) {
        printf("%d\n", -1);
        return 0;
    }

    dp[0][0] = 0LL;
    rep1(i, n) dp[0][i] = 0LL;
    rep1(i, n) dp[i][0] = 0LL;
    rep1(i, n) rep1(j, m) {
        if (j > i) {
            dp[i][j] = -INF;
        } else {
            ll dpp = -INF;
            rep(l, k) {
                if (i - k + l < 0LL)
                    continue;
                dpp = max(dpp, dp[i - k + l][j - 1LL]);
            }
            dp[i][j] = dpp + a[i];
        }
    }

    ll ret = -INF;
    rep1(i, k) {
        if (n - k + i < 0)
            continue;
        ret = max(ret, dp[n - k + i][m]);
    }
    printf("%lld\n", ret);

    /* --------------------------------- */
    return 0;
}