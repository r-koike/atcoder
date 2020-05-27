/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2019.06.22 20:57:36
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
ll n;
ll a1, b1;
vector<P> vec;

int main() {
    scanf("%lld", &n);
    rep(i, n) {
        scanf("%lld%lld", &a1, &b1);
        vec.pb(P(a1, b1));
    }

    sort(vec.begin(), vec.end(), [](const P a, const P b) {
        if (a.sc != b.sc)
            return a.sc < b.sc;
        else
            return a.fr < b.fr;
    });

    ll time = 0;
    rep(i, n) {
        ll a = vec[i].fr;
        ll b = vec[i].sc;
        time += a;
        if (time > b) {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");

    /* --------------------------------- */
    return 0;
}