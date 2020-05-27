/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2019.05.09 17:00:38
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
const int M = 100000000;
const int dir_4[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int dir_8[8][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

/* ------------------------------------- */

int main() {
    ll n, k, a[100010];
    scanf("%lld%lld", &n, &k);
    rep(i, n) scanf("%lld", &a[i]);

    ll kl = 0;
    while (1) {
        if ((1LL << kl) > k)
            break;
        kl++;
    }

    ll zl, ol;
    ll at[100010];
    rep(i, n) at[i] = a[i];
    vector<bool> vec;
    rep(i, kl) {
        zl = ol = 0;
        rep(j, n) {
            if (at[j] % 2 == 0) {
                zl++;
            } else {
                ol++;
            }
            at[j] /= 2;
        }
        if (zl > ol) {
            vec.pb(true);
        } else {
            vec.pb(false);
        }
    }

    ll x = 0;
    rep(i, kl) {
        if (vec[i]) {
            x += 1LL << i;
        }
    }
    if (x > k)
        x /= 2;

    ll ret = 0;
    rep(i, n) {
        ret += x ^ a[i];
    }

    printf("%lld\n", ret);

    /* --------------------------------- */
    return 0;
}