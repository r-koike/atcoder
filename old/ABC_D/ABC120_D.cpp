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

const ll INF = 100000000;
const ll M = 100000000;
const ll dir_4[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const ll dir_8[8][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

/* ------------------------------------- */
const ll UF_SIZE = 100010;

ll par[UF_SIZE]; // 親
ll siz[UF_SIZE]; // 木の深さ

// n要素で初期化
void init(ll n) {
    for (ll i = 0; i < n; i++) {
        par[i] = i;
        siz[i] = 1;
    }
}

// 木の根を求める
ll find(ll x) {
    if (par[x] == x) {
        return x;
    } else {
        return par[x] = find(par[x]);
    }
}

// xとyの属する集合を併合
void unite(ll x, ll y) {
    x = find(x);
    y = find(y);
    if (x == y)
        return;

    if (siz[x] < siz[y]) {
        par[x] = y;
        siz[y] += siz[x];
    } else {
        par[y] = x;
        siz[x] += siz[y];
    }
}

// xとyが同じ集合に属するか否か
bool same(ll x, ll y) {
    return find(x) == find(y);
}

// xが属する集合の要素数
ll size(ll x) {
    return siz[find(x)];
}

ll n, m, a[100010], b[100010];
int main() {
    scanf("%lld%lld", &n, &m);
    rep(i, m) scanf("%lld%lld", &a[i], &b[i]);
    rep(i, m) {
        a[i]--;
        b[i]--;
    }

    init(n);
    ll rets[100010];
    rets[m] = n * (n - 1) / 2;
    rrep(i, m) {
        if (same(a[i], b[i])) {
            rets[i] = rets[i + 1];
        } else {
            rets[i] = rets[i + 1] - size(a[i]) * size(b[i]);
        }
        unite(a[i], b[i]);
    }

    rep1(i, m) {
        printf("%lld\n", rets[i]);
    }

    /* --------------------------------- */
    printf("\n");
    return 0;
}