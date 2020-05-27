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

const int INF = 1000000100;
const int M = 100000000;
const int dir_4[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int dir_8[8][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

/* ------------------------------------- */
struct edge {
    int to, cost;
};

// Vは辺の数、Eは頂点の数
int V, E, k;
vector<edge> g[2020];
int d[1010];
P hana[1010];

void dijkstra(int s) {
    priority_queue<P, vector<P>, greater<P>> que;
    fill(d, d + V, INF);
    d[s] = 0;
    // firstは最短距離、secondは頂点の番号
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.sc;
        if (d[v] < p.fr)
            continue;
        rep(i, g[v].size()) {
            edge e = g[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main() {
    scanf("%d%d%d", &E, &V, &k);
    int a, b, c;
    rep(i, V) {
        scanf("%d%d%d", &a, &b, &c);
        a--;
        b--;
        g[a].pb({b, c});
        g[b].pb({a, c});
    }
    int x, y;
    rep(i, E) {
        scanf("%d%d", &x, &y);
        hana[i] = P(x, y);
    }

    /* --------------------------------- */
    return 0;
}