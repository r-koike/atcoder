/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2019.05.10 12:50:20
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

ll dp[110][8];
int com[8] = {1, 1, 2, 3, 5, 8, 13, 21}; // i個のあみだ1段で何通り作れるか

int main() {
    ll h, w, k;
    scanf("%lld%lld%lld", &h, &w, &k);

    dp[0][0] = 1LL;
    rep1(i, h) rep(j, w) {
        ll a0 = 0, a1 = 0, a2 = 0;
        if (j != 0) {
            if (w > 3) {
                ll t = j - 1 >= 0 ? com[j - 1] : 1;
                t *= w - j - 1 >= 0 ? com[w - j - 1] : 1;
                a0 = dp[i - 1][j - 1] * t;
            } else {
                a0 = dp[i - 1][j - 1];
            }
        }
        if (j != w - 1) {
            if (w > 3) {
                ll t = j >= 0 ? com[j] : 1;
                t *= w - j - 2 >= 0 ? com[w - j - 2] : 1;
                a1 = dp[i - 1][j + 1] * t;
            } else {
                a1 = dp[i - 1][j + 1];
            }
        }
        if (1) {
            if (w > 2) {
                ll t = j >= 0 ? com[j] : 1;
                t *= w - j - 1 >= 0 ? com[w - j - 1] : 1;
                a2 = dp[i - 1][j] * t;
            } else {
                a2 = dp[i - 1][j];
            }
        }
        // printf("i:%lld j:%lld %lld %lld %lld\n", i, j, a0, a1, a2);
        dp[i][j] = (a0 + a1 + a2) % M;
    }

    // rep(i, h + 1) {
    //     rep(j, w) {
    //         printf("i:%lld j:%lld dp:%lld\n", i, j, dp[i][j]);
    //     }
    //     printf("\n");
    // }

    printf("%lld\n", dp[h][k - 1]);

    /* --------------------------------- */
    return 0;
}