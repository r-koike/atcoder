/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2019.05.09 18:01:59
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
bool isSelSpe[100010];
ll dp[100010];
ll selnum = 0;
ll selnumf = 0;

int main() {
    ll k, n;
    vector<P> vec;
    scanf("%lld%lld", &n, &k);
    rep(i, n) {
        ll t_, d_;
        scanf("%lld%lld", &t_, &d_);
        vec.pb(P(t_, d_));
    }

    sort(vec.begin(), vec.end(), [](const P a, const P b) {
        if (a.sc != b.sc)
            return a.sc < b.sc;
        else
            return a.fr > b.fr;
    });

    vector<ll> queconst;
    priority_queue<ll, vector<ll>, greater<ll>> que;

    ll sum = 0;
    rep(i, k) {
        P p = vec.back();
        vec.pop_back();
        if (!isSelSpe[p.fr]) {
            selnum++;
            isSelSpe[p.fr] = true;
            sum += p.sc;
            queconst.pb(p.sc);
        } else {
            sum += p.sc;
            que.push(p.sc);
        }
    }

    dp[selnum] = sum + selnum * selnum;
    selnumf = selnum;

    bool cnt = false;
    while (!que.empty()) {
        cnt = false;
        ll qs = que.top();
        que.pop();
        while (!vec.empty()) {
            P p = vec.back();
            vec.pop_back();
            if (isSelSpe[p.fr])
                continue;
            dp[selnum + 1] = dp[selnum] - selnum * selnum - qs;
            dp[selnum + 1] += (selnum + 1) * (selnum + 1) + p.sc;
            queconst.pb(p.sc);
            isSelSpe[p.fr] = true;
            selnum++;
            cnt = true;
            break;
        }
        if (!cnt) {
            que.push(qs);
            break;
        }
    }

    ll ret = 0;
    for (ll i = selnumf; i < selnum + 1; i++) {
        ret = max(ret, dp[i]);
    }

    printf("%lld", ret);

    /* --------------------------------- */
    return 0;
}