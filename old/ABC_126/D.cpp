/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2019.05.19 20:58:46
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

const int INF = 1000000007;
const int M = 100000000;
const int dir_4[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int dir_8[8][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

/* ------------------------------------- */

// 頂点fromから頂点toへのコストcostの辺
struct edge {
    int to;
    ll cost;
};

int v, e;
ll costs[100010];

vector<edge> G[100010];

void dfs(int from, int to, ll cost, ll sumcost) {
    costs[to] = sumcost + cost;
    rep(i, G[to].size()) {
        if (G[to][i].to != from) {
            dfs(to, G[to][i].to, G[to][i].cost, costs[to]);
        }
    }
}

int main() {
    // vは頂点数、eは辺の数
    scanf("%d", &v);
    int ut, vt, wt;
    rep(i, v - 1) {
        scanf("%d%d%d", &ut, &vt, &wt);
        G[ut - 1].pb({vt - 1, wt});
        G[vt - 1].pb({ut - 1, wt});
    }
    costs[0] = 0;
    rep(i, G[0].size()) {
        dfs(0, G[0][i].to, G[0][i].cost, costs[0]);
    }
    rep(i, v) {
        // printf("i: %d, cost:%lld\n", i, costs[i]);
        if (i == 0) {
            printf("%d\n", 0);
            continue;
        }
        if (costs[i] % 2 == 0) {
            printf("%d\n", 0);
        } else {
            printf("%d\n", 1);
        }
    }

    /* --------------------------------- */
    return 0;
}