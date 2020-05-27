/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2019.05.11 21:57:18
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

ll n;
ll a[500010];

int main() {
    scanf("%lld", &n);
    rep(i, n) scanf("%lld", &a[i]);

    ll ret = 0;
    rep1(i, n - 1) {
        ll sum0 = 0;
        rep(j, i) {
            sum0 = sum0 ^ a[j];
        }
        ll sum1 = 0;
        ll cnt = 0;
        bool first = true;
        ll t = 1;
        queue<ll> que;
        for (ll j = i; j < n; j++) {
            if (first && a[j] == 0 && sum0 != 0) {
                t++;
                continue;
            } else if (first) {
                if (t > 1) {
                    que.push(t);
                }
                first = false;
            }
            sum1 ^= a[j];
            if (sum1 == sum0) {
                cnt++;
                sum1 = 0;
                first = true;
                t = 1;
            }
        }
        if (cnt > 0 && first) {
            ll rett;
            if (cnt - que.size() - 1 >= 0) {
                rett = 1LL << (cnt - que.size() - 1);
            } else {
                rett = 1;
            }

            while (!que.empty()) {
                ll tt = que.back();
                que.pop();
                rett = rett * (t + 1LL);
            }
            ret = (ret + rett) % M;
            printf("i:%lld sum0:%lld ret:%lld\n", i, sum0, ret);
        }
    }
    ret = (ret + 1) % M;

    printf("%lld\n", ret);

    /* --------------------------------- */
    return 0;
}