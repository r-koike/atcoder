/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2019.06.29 20:58:50
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

vector<int> G[100010];
int ret[100010][3];

void dfs(int u, int step, int time) {
    step = (step + 1) % 3;
    if (step == 0) {
        time++;
    }
    rep(i, G[u].size()) {
        if (ret[G[u][i]][step] > time) {
            ret[G[u][i]][step] = time;
            dfs(G[u][i], step, time);
        }
    }
    return;
}

int main() {
    int n, m, s, t;
    scanf("%d%d", &n, &m);
    int ut, vt;
    rep(i, m) {
        scanf("%d%d", &ut, &vt);
        G[ut - 1].pb(vt - 1);
    }
    scanf("%d%d", &s, &t);
    s--;
    t--;

    rep(i, 3) rep(j, 100010) {
        ret[j][i] = INF;
    }

    ret[s][0] = 0;

    dfs(s, 0, 0);

    if (ret[t][0] != INF) {
        printf("%d\n", ret[t][0]);
    } else {
        printf("%d\n", -1);
    }

    /* --------------------------------- */
    return 0;
}