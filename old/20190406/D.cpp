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

//#define int long long

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

const ll INF = 10000000000000000;
const ll M = 100000000;
const ll dir_4[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const ll dir_8[8][2] = {{1, 0},  {1, 1},   {0, 1},  {-1, 1},
                        {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

/* ------------------------------------- */

int main() {
    ll x, y, z, k, a[1010], b[1010], c[1010];
    scanf("%lld%lld%lld%lld", &x, &y, &z, &k);
    rep(i, x) scanf("%lld", &a[i]);
    rep(i, y) scanf("%lld", &b[i]);
    rep(i, z) scanf("%lld", &c[i]);
    vector<ll> av, bv, cv;
    rep(i, x) av.pb(a[i]);
    rep(i, y) bv.pb(b[i]);
    rep(i, z) cv.pb(c[i]);
    rev(av);
    rev(bv);
    rev(cv);

    ll ai = 0, bi = 0, ci = 0;
    rep(i, k) {
        ll ret = av[ai] + bv[bi] + cv[ci];
        printf("%lld", ret);
        printf("%lld,%lld,%lld", ai, bi, ci);
        printf("\n");
        if (i == k - 1)
            break;
        ll m = INF;
        int down = -1;
        if (ai < x - 1) {
            if (m > av[ai] - av[ai + 1]) {
                m = av[ai] - av[ai + 1];
                down = 0;
            }
        }
        if (bi < y - 1) {
            if (m > bv[bi] - bv[bi + 1]) {
                m = bv[bi] - bv[bi + 1];
                down = 1;
            }
        }
        if (ci < z - 1) {
            if (m > cv[ci] - cv[ci + 1]) {
                m = cv[ci] - cv[ci + 1];
                down = 2;
            }
        }
        if (down == 0) {
            ai++;
        } else if (down == 1) {
            bi++;
        } else if (down == 2) {
            ci++;
        }
    }

    /* --------------------------------- */
    return 0;
}