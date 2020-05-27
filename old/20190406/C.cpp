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
    ll a[5], n;
    scanf("%lld%lld%lld%lld%lld%lld", &n, &a[0], &a[1], &a[2], &a[3], &a[4]);
    ll m = INF;
    rep(i, 5) {
        m = min(m, a[i]);
    }
    if (n <= m) {
        printf("%d", 5);
        printf("\n");
        return 0;
    }
    ll ret = 0;
    if (n % m == 0) {
        ret = n / m;
    } else {
        ret = n / m + 1;
    }
    ret += 4;
    printf("%lld", ret);

    /* --------------------------------- */
    return 0;
}