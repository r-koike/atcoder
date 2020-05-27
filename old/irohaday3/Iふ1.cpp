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
const int M = 100000000;
const int dir_4[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int dir_8[8][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

/* ------------------------------------- */
const int N = 100001;

bool dp[N];

ll cnt[10000001];

int main() {
    int n = 100000;

    for (int i = 2; i <= n; i++)
        dp[i] = true;
    for (int i = 2; i <= sqrt(n); i++) {
        if (!dp[i])
            continue;
        for (int j = 2; i * j <= n; j++) {
            dp[i * j] = false;
        }
    }

    rep(m, 20) {
        ll def = 90000000 + m * 10000000;
        // dp[i]はiが素数であるかどうか
        ll i = 9000000000000000LL;
        cnt[0] = 0;
        bool b;
        ll p;
        for (ll j = 1; j <= 10000000; j++) {
            p = i + j + def;
            b = true;
            for (int k = 2; k < 100000; k++) {
                if (!dp[k])
                    continue;
                if (p % k == 0) {
                    b = false;
                    break;
                }
            }
            cnt[j] = cnt[j - 1] + (b ? 1 : 0);
        }
        ll ma = 0;
        for (ll j = 0; j <= 10000000 - 3000; j++) {
            ll cur = cnt[j + 2019] - cnt[j];
            if (ma < cur) {
                ma = cur;
                printf("ma:%lld j:%lld\n", ma, j + 1 + def);
            }
        }
    }

    /* --------------------------------- */
    return 0;
}