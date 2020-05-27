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
#define rep(i, x) for (int i = 0; i < x; i++)
#define rep1(i, x) for (int i = 1; i <= x; i++)
#define rrep(i, x) for (int i = x - 1; i >= 0; i--)
#define rrep1(i, x) for (int i = x; i > 0; i--)
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

// ===================### Union-Findの実装 ###=================== //
const int UF_SIZE = 200010;

int par[UF_SIZE]; // 親
int siz[UF_SIZE]; // 木の深さ

// n要素で初期化
void init(int n) {
    for (int i = 0; i < n; i++) {
        par[i] = i;
        siz[i] = 1;
    }
}
// 木の根を求める
int find(int x) {
    if (par[x] == x) {
        return x;
    } else {
        return par[x] = find(par[x]);
    }
}
// xとyの属する集合を併合
void unite(int x, int y) {
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
bool same(int x, int y) {
    return find(x) == find(y);
}
// xが属する集合の要素数
int size(int x) {
    return siz[find(x)];
}

struct edge {
    int u, v, cost, idx;
};

bool comp(const edge &e1, const edge &e2) {
    return e1.cost > e2.cost;
}

edge es[400010];
int ret[200010];
int ri;
int V, E;

int main() {
    scanf("%d%d", &V, &E);
    int at, bt, ct;
    rep(i, E) {
        scanf("%d%d%d", &at, &bt, &ct);
        es[i] = {at, bt, ct, i + 1};
    }

    sort(es, es + E, comp); // costが大きい順にソート
    init(V);

    rep(i, E) {
        edge e = es[i];
        if (!same(e.u, e.v)) {
            unite(e.u, e.v);
            ret[ri] = e.idx;
            ri++;
        }
    }
    sort(ret, ret + ri);
    rep(i, ri) printf("%d\n", ret[i]);

    /* --------------------------------- */
    return 0;
}