/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2019.07.07 22:01:47
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

int n, q, a[100010], b[100010], c[100010], d[100010];
int x[100010], y[100010], u[100010], v[100010];
vector<int> G[100010];

int parent[100010];
int depth[100010];
int root;

void dfs(int v, int p, int d) {
    parent[v] = p;
    depth[v] = d;
    for (int i = 0; i < G[v].size(); i++) {
        if (G[v][i] != p)
            dfs(G[v][i], v, d + 1);
    }
}
void init() {
    dfs(root, -1, 0);
}
int lca(int u, int v) {
    while (depth[u] > depth[v])
        u = parent[u];
    while (depth[v] > depth[u])
        v = parent[v];
    while (u != v) {
        v = parent[v];
        u = parent[u];
    }
    return u;
}

/* ------------------------------------- */

int dist[100010], cdist[100010][100010];

int main() {
    scanf("%d%d", &n, &q);
    rep(i, n - 1) {
        int aa, bb;
        scanf("%d%d", &aa, &bb);
        G[aa - 1].pb(bb - 1);
        G[bb - 1].pb(aa - 1);
        int cc, dd;
        scanf("%d%d", &cc, &dd);
    }
    rep(i, q) {
        scanf("%d%d%d%d", &x[i], &y[i], &u[i], &v[i]);
        u[i]--;
        v[i]--;
    }

    // lca用
    root = 0;
    init();

    int par = lca(3, 4);
    cout << par << endl;

    /* --------------------------------- */
    return 0;
}