/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2019.06.09 20:55:30
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

bool field[2005][2005];
int ret[2005][2005];

int main() {
    int h, w;
    cin >> h >> w;
    string s;
    rep(i, h) {
        cin >> s;
        rep(j, w) {
            if (s[j] == '#') {
                field[i][j] = false;
            } else {
                field[i][j] = true;
            }
        }
    }
    rep(i, h) rep(j, w) {
        ret[i][j] = 0;
    }
    rep(i, h) {
        int cnt = 0;
        rep(j, w) {
            if (field[i][j]) {
                cnt++;
            } else {
                ret[i][j] = 0;
                if (cnt > 0) {
                    rep(k, cnt) {
                        ret[i][j - k - 1] += cnt;
                    }
                    cnt = 0;
                }
            }
        }
        if (cnt > 0) {
            rep(k, cnt) {
                ret[i][w - 1 - k] += cnt;
            }
        }
    }

    rep(j, w) {
        int cnt = 0;
        rep(i, h) {
            if (field[i][j]) {
                cnt++;
            } else {
                ret[i][j] = 0;
                if (cnt > 0) {
                    rep(k, cnt) {
                        ret[i - k - 1][j] += cnt;
                    }
                    cnt = 0;
                }
            }
        }
        if (cnt > 0) {
            rep(k, cnt) {
                ret[h - 1 - k][j] += cnt;
            }
        }
    }

    int ma = -1;
    rep(i, h) rep(j, w) {
        ma = max(ma, ret[i][j]);
    }

    cout << ma - 1 << "\n";

    // rep(i, h) {
    //     rep(j, w) {
    //         cout << ret[i][j];
    //     }
    //     cout << endl;
    // }

    /* --------------------------------- */
    return 0;
}