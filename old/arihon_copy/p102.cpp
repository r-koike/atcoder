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
struct edge {
    int u, v, cost;
}

int n,
    r;
vector<edge> g[10010];

int dist[10010];
int dist2[10010];

int main() {
    priority_queue<P, vector<P>, greater<P>> que;
    fill(dist, dist + n, INF);
    fill(dist2, dist2 + n, INF);
    dist[0] = 0;
    que.push(P(0, 0));

    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.sc, d = p.fr;
        if (dist2[v] < d)
            continue;
        rep(i, g[v].size()) {
            edge &e = g[v][i];
            int d2 = d + e.cost;
            if (dist[e.to] > d2) {
                swap(dist[e.to], d2);
                que.push(P(dist[e.to], e.to));
            }
            if (dist2[e.to] > d2 && dist[e.to] < d2) {
                dist2[e.to] = d2;
                que.push(P(dist2[e.to], e.to));
            }
        }
    }
    printf("%d\n", dist2[n - 1]);

    /* --------------------------------- */
    return 0;
}