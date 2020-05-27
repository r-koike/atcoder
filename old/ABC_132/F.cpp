/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2019.06.29 22:16:36
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

// ===================### 素数取得 ###=================== //
bool primeDp[100000];
vector<ll> getPrimes(int n) {
    int u = n + 32;
    double lu = log(u);
    vector<ll> ret((int)(u / lu + u / lu / lu * 1.5));

    for (int i = 2; i <= n; i++)
        primeDp[i] = true;
    int sqn = sqrt(n);
    for (int i = 2; i <= sqn; i++) {
        if (!primeDp[i])
            continue;
        for (int j = i * i; j <= n; j += i)
            primeDp[j] = false;
    }
    int idx = 0;
    for (int i = 2; i <= n; i++) {
        if (primeDp[i]) {
            ret[idx] = i;
            idx++;
        }
    }
    return vector<ll>(ret.begin(), ret.begin() + idx);
}
/* ------------------------------------- */

ll dp[110][100000];
ll dpsum[110][100000];

int main() {
    ll n, k;
    scanf("%lld%lld", &n, &k);
    ll sqn = sqrt(n);

    vector<ll> yakusu;

    rep1(i, sqn) {
        yakusu.pb(i);
        yakusu.pb(n / i);
    }

    sor(yakusu);
    ll yl = yakusu.size();

    rep1(i, k) {
        if (i == 1) {
            rep(j, yl) {
                if (j == 0) {
                    dp[i][j] = yakusu[j];
                    dpsum[i][j] = dp[i][j];
                } else {
                    dp[i][j] = (yakusu[j] - yakusu[j - 1]) % M;
                    dpsum[i][j] = (dpsum[i][j - 1] + dp[i][j]) % M;
                }
            }
            continue;
        }
        rep(j, yl) {
            ll id;
            // if (yl % 2 == 1) {
            //     if (yl / 2 < j) {
            //         id = yl - j - 1;
            //     } else if (yl / 2 > j) {
            //         id = yl - j - 1;
            //     } else {
            //         id = yl / 2;
            //     }
            // } else {
            //     id = yl - j - 1;
            // }
            id = yl - j - 1;

            if (j == 0) {
                dp[i][j] = (dpsum[i - 1][id] * (yakusu[j])) % M;
            } else {
                dp[i][j] = (dpsum[i - 1][id] * (yakusu[j] - yakusu[j - 1])) % M;
            }
            // printf("%lld %lld %lld\n", i, j, dp[i][j]);
        }
        rep(j, yl) {
            if (j == 0) {
                dpsum[i][j] = dp[i][j];
                continue;
            }
            dpsum[i][j] = (dpsum[i][j - 1] + dp[i][j]) % M;
        }
        // printf("i: %lld, dpsum:%lld\n", i, dpsum[i][yl - 1]);
    }

    printf("%lld\n", dpsum[k][yl - 1]);

    /* --------------------------------- */
    return 0;
}