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

const int INF = 100000000;
const ll M = 100000000;
const int dir_4[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int dir_8[8][2] = {{1, 0},  {1, 1},   {0, 1},  {-1, 1},
                         {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

/*----------------------------------------------/
/- char         : %c  | char *       : %s  | short        : %hd
/- int          : %d  | long         : %ld | long long    : %lld
/- unsigned short:%hu | unsigned int : %u  | unsigned long: %lu
/- u_long long  : %llu| (octal)      : %o  | (hexadecimal): %x
/- float        : %f  | double       : %lf |
/----------------------------------------------*/

/*----------------------------------------------/
/- INT_MAX, LONG_MAX   : 1<<15 = 2.1*pow(10, 9)       (= 2147483647)
/- UINT_MAX, ULONG_MAX : 1<<16 = 4.2*pow(10, 9)       (= 4294967295)
/- LLONG_MAX           : 1<<63 = 9.2*pow(10, 18)      (= 9223372036854775807)
/- ULLONG_MAX          : 1<<64 = 1.8*pow(10, 19)      (= 18446744073709551615)
/----------------------------------------------*/

char maze[1010][1010];
int h, w, n;
int sx, sy;
int gx, gy;

int d[1010][1010];

int bfs() {
    queue<P> que;
    // 全ての点をINFで初期化
    rep(i, h) rep(j, w) d[i][j] = INF;
    // スタート地点をキューに入れ、その点の距離を0にする
    que.push(P(sx, sy));
    d[sy][sx] = 0;

    // キューが空になるまでループ
    while (que.size()) {
        // キューの先頭を取り出す
        P p = que.front();
        que.pop();
        if (p.fr == gx && p.sc == gy)
            break;

        rep(i, 4) {
            // 移動した後の点を(nx, ny)とする
            int nx = p.fr + dir_4[i][0];
            int ny = p.sc + dir_4[i][1];

            // 移動は可能か、すでに訪れたことはあるか
            if (0 <= nx && nx < w && 0 <= ny && ny < h && maze[ny][nx] != 'X' &&
                d[ny][nx] == INF) {
                // 移動できるならキューに入れ、その点の距離をpからの距離+1で確定する
                que.push(P(nx, ny));
                d[ny][nx] = d[p.sc][p.fr] + 1;
            }
        }
    }
    return d[gy][gx];
}

char getC(int i) {
    switch (i) {
    case 0:
        return 'S';
    case 1:
        return '1';
    case 2:
        return '2';
    case 3:
        return '3';
    case 4:
        return '4';
    case 5:
        return '5';
    case 6:
        return '6';
    case 7:
        return '7';
    case 8:
        return '8';
    case 9:
        return '9';
    }
}

int main() {
    cin >> h >> w >> n;
    rep(i, h) rep(j, w) { scanf(" %c", &maze[i][j]); };

    int ret = 0;
    rep(k, n) {
        char s = getC(k);
        char g = getC(k + 1);
        rep(i, h) rep(j, w) {
            if (maze[i][j] == s) {
                sy = i;
                sx = j;
            } else if (maze[i][j] == g) {
                gy = i;
                gx = j;
            }
        }
        ret += bfs();
    }
    cout << ret;

    /* ====================================== */
    cout << endl;
    return 0;
}