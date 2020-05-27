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
char maze[1010][1010];
int n, m;
int sx, sy;
int gx, gy;

int d[1010][1010];

int bfs() {
    queue<P> que;
    rep(i, n) rep(j, m) {
        d[i][j] = INF;
    }
    que.push(P(sx, sy));
    d[sx][sy] = 0;

    while (que.size()) {
        P p = que.front();
        que.pop();
        if (p.fr == gx && p.sc == gy) {
            break;
        }
        rep(i, 4) {
            int nx = p.fr + dir_4[i][0];
            int ny = p.sc + dir_4[i][1];

            if (0 <= nx && nx < N && 0 <= ny && ny < M && maze[nx][ny] != '#' &&
                d[nx][ny] == INF) {
                que.push(P(nx, ny));
                d[nx][ny] = d[p.fr][p.sc] + 1;
            }
        }
    }
    return d[gx][gy];
}

int main() {
    int ret = bfs();
    printf("%d\n", ret);

    /* --------------------------------- */
    return 0;
}