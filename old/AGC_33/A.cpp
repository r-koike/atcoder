/**
 * @brief : c++ code for AtCoder
 * @author: rk222
 * @created: 2019.05.04 20:57:56
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
int h, w;
int field[1010][1010];
bool fb[1010][1010];

int main() {
    scanf("%d%d", &h, &w);
    rep(i, h) rep(j, w) {
        char c;
        scanf(" %c", &c);
        if (c == '.') {
            field[i][j] = -1;
            fb[i][j] = true;
        } else if (c == '#') {
            field[i][j] = 0;
        }
    }

    int k = 0;
    int dy, dx, ny, nx;
    bool updated = false;

    while (1) {
        updated = false;
        rep(i, h) rep(j, w) {
            if (fb[i][j])
                continue;
            if (field[i][j] == k) {
                rep(l, 4) {
                    ny = i + dir_4[l][0];
                    nx = j + dir_4[l][1];
                    if (0 <= nx && nx < w && 0 <= ny && ny < h && field[ny][nx] == -1) {
                        field[ny][nx] = k + 1;
                        fb[ny][nx] = false;
                        updated = true;
                    }
                }
                fb[i][j] = true;
            }
        }
        if (!updated) {
            break;
        }
        k++;
    }

    printf("%d\n", k);

    /* --------------------------------- */
    return 0;
}