/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2019.06.22 20:57:26
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
ll gcd(ll a, ll b) {
    if (a % b == 0) {
        return (b);
    } else {
        return (gcd(b, a % b));
    }
}

int main() {
    ll a, b, c, d;
    scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
    ll c1, c2, d1, d2, cd1, cd2;
    if (c < d) {
        swap(c, d);
    }
    ll lcm = c * d / gcd(c, d);
    c1 = (a - 1) / c;
    c2 = b / c;
    d1 = (a - 1) / d;
    d2 = b / d;
    cd1 = (a - 1) / lcm;
    cd2 = b / lcm;

    ll ret = (b - a + 1) - (c2 - c1) - (d2 - d1) + (cd2 - cd1);

    printf("%lld\n", ret);

    /* --------------------------------- */
    return 0;
}