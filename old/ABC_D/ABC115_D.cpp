/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2019.05.09 19:19:37
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
ll cnt[60];

ll solve(ll lv, ll x) {
    if (lv == 0)
        return 1LL;
    ll cn = cnt[lv];
    if (x == 1) {
        return 0LL;
    } else if (1LL < x && x <= cn / 2) {
        return solve(lv - 1, x - 1);
    } else if (x == cn / 2 + 1) {
        return solve(lv - 1, cnt[lv - 1]) + 1;
    } else if (x > cn / 2 + 1 && x < cn) {
        return solve(lv - 1, cnt[lv - 1]) + solve(lv - 1, x - cn / 2 - 1) + 1;
    } else if (x >= cn) {
        return solve(lv - 1, cnt[lv - 1]) * 2 + 1;
    }
    return -1LL;
}

int main() {
    ll n, x;
    scanf("%lld%lld", &n, &x);

    cnt[0] = 1;
    rep1(i, n) {
        cnt[i] = 2 * cnt[i - 1] + 3;
    }

    printf("%lld\n", solve(n, x));

    /* --------------------------------- */
    return 0;
}