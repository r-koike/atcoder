/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2019.12.28 20:11:35
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

const ll INF = 100000000;
const ll M = 100000000;
const ll dir_4[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const ll dir_8[8][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

/* ------------------------------------- */

int main() {
    ll n, a, b;
    scanf("%lld%lld%lld", &n, &a, &b);

    ll ret = -1;
    if (abs(a - b) % 2 == 0) {
        ret = abs(a - b) / 2;
    } else {
        ll x1, x2;
        x1 = min(abs(a - 1), abs(b - 1));
        x2 = min(abs(a - n), abs(b - n));
        ll x3 = min(x1, x2);
        ret = x3 + (abs(a - b) + 1) / 2;
    }

    printf("%lld\n", ret);

    /* --------------------------------- */
    return 0;
}