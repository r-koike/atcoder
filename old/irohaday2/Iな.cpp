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

const ll INF = 100000000000;
const int M = 100000000;
const int dir_4[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int dir_8[8][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

/* ------------------------------------- */
struct edge {
    int from, to;
};
vector<edge> es;

int h, w, x, sx, sy, gx, gy;
int field[555][555];
ll cost[250100];

const int START = 250010;
const int GOAL = 250011;
const int TANSAKUZUMI = -250020;

ll d[250100];
// Vは頂点、Eは辺
int V, E;

bool firsttry = true;
bool ext = false;

void dfs(int x, int y, int cur) {
    if (firsttry && x == gx && y == gy) {
        printf("%d\n", 0);
        ext = true;
        return;
    }
    if (field[x][y] != 0) {
        field[x][y] = TANSAKUZUMI;
    } else {
        field[x][y] = -cur;
    }

    rep(i, 4) {
        int dx = dir_4[i][0];
        int dy = dir_4[i][1];
        int nx = x + dx, ny = y + dy;
        bool onfield = 0 <= nx && nx < h && 0 <= ny && ny < w;
        int f = field[nx][ny];
        if (onfield && (f == cur || f == 0 || (f < 0 && f != TANSAKUZUMI && f != -cur))) {
            dfs(nx, ny, cur);
        } else if (onfield && f != cur && field[nx][ny] > 0) {
            es.pb({cur, field[nx][ny]});
        }
    }
    return;
}

/* ------------------------------------- */

void shortest_path(int s) {
    rep(i, 250100) d[i] = INF;
    d[s] = 0;
    while (1) {
        bool update = false;
        rep(i, es.size()) {
            rep(j, 2) {
                int from = es[i].from;
                int to = es[i].to;
                if (j)
                    swap(to, from);
                int cst;
                if (to == START || to == GOAL) {
                    cst = 0;
                } else {
                    cst = cost[to];
                }
                if (d[from] != INF && d[to] > d[from] + cst) {
                    d[to] = d[from] + cst;
                    update = true;
                }
            }
        }
        if (!update)
            break;
    }
}

/* ------------------------------------- */

int main() {
    scanf("%d%d%d", &h, &w, &x);
    scanf("%d%d%d%d", &sx, &sy, &gx, &gy);
    int a;
    sx--;
    sy--;
    gx--;
    gy--;

    rep(i, h) rep(j, w) {
        scanf("%d", &a);
        field[i][j] = a;
    }
    ll b;
    rep(i, x) {
        scanf("%lld", &b);
        cost[i + 1] = b;
    }

    dfs(sx, sy, START);
    if (ext)
        return 0;
    firsttry = false;

    dfs(gx, gy, GOAL);

    rep(i, h) rep(j, w) {
        if (field[i][j] > 0) {
            dfs(i, j, field[i][j]);
        }
    }

    sort(es.begin(), es.end(), [](const edge a, const edge b) {
        if (a.from != b.from)
            return a.from < b.from;
        else
            return a.to < b.to;
    });
    es.erase(
        unique(es.begin(), es.end(),
               [](const edge a, const edge b) { return a.from == b.from && a.to == b.to; }),
        es.end());

    // rep(i, es.size()) {
    //     printf("from:%d to:%d\n", es[i].from, es[i].to);
    // }
    // cout << endl;

    shortest_path(START);

    printf("%lld\n", d[GOAL]);

    /* --------------------------------- */
    return 0;
}