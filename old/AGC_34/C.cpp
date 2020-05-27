/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2019.06.02 20:56:10
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
ll n, x;

int main() {
    vector<pair<ll, pair<ll, ll>>> blu;
    scanf("%lld%lld", &n, &x);
    rep(i, n) {
        ll bt, lt, ut;
        scanf("%lld%lld%lld", &bt, &lt, &ut);
        blu.pb(P1(bt, P(lt, ut)));
    }

    // ソート
    sort(blu.begin(), blu.end(), [](const P1 a1, const P1 a2) {
        ll b1 = a1.fr;
        ll l1 = a1.sc.fr;
        ll u1 = a1.sc.sc;
        ll b2 = a2.fr;
        ll l2 = a2.sc.fr;
        ll u2 = a2.sc.sc;
        ll ret1, ret2;
        ret1 = u1 * (x - b1);
        ret2 = u2 * (x - b2);
        if (ret1 != ret2)
            return ret1 < ret2;
        else
            return l1 < l2;
    });

    ll sum = 0;
    rep(i, n) {
        ll b = blu[i].fr;
        ll l = blu[i].sc.fr;
        sum -= l * b;
    }

    // rep(i, n) {
    //     ll b1 = blu[i].fr;
    //     ll l1 = blu[i].sc.fr;
    //     ll u1 = blu[i].sc.sc;
    //     printf("%lld,%lld,%lld\n", b1, l1, u1);
    // }

    ll ret = 0;
    while (1) {
        // cout << sum << endl;
        ll b = blu.back().fr;
        ll l = blu.back().sc.fr;
        ll u = blu.back().sc.sc;
        sum += u * (x - b) + l * b;
        if (sum == 0) {
            ret += x;
            break;
        } else if (sum > 0) {
            sum -= u * (x - b) + l * b;
            sum = (-1LL) * sum;
            ll mn = 1000000;
            rep(i, blu.size()) {
                ll b1 = blu[i].fr;
                ll l1 = blu[i].sc.fr;
                ll u1 = blu[i].sc.sc;
                if (b1 * l1 >= sum) {
                    mn = min(mn, (ll)((sum - 1) / l1) + 1);
                } else {
                    mn = min(mn, (ll)((sum - b1 * l1 - 1) / u1 + b1 + 1));
                }
                // cout << mn << endl;
            }
            ret += mn;
            break;
        } else {
            ret += x;
            blu.pop_back();
        }
    }

    printf("%lld\n", ret);

    /* --------------------------------- */
    return 0;
}