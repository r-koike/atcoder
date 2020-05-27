/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2019.06.22 20:57:53
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

vector<int> field[100010];
vector<int> field2[100010];

int n, x[100010], y[100010];

int main() {
    scanf("%d", &n);
    rep(i, n) scanf("%d%d", &x[i], &y[i]);

    ll ret = 0;
    rep(i, n) {
        bool b = binary_search(field[x[i]].begin(), field[x[i]].end(), y[i]);
        if (b) {
            ret--;
        } else {
            field[x[i]].pb(y[i]);
            field2[y[i]].pb(x[i]);
            sor(field[x[i]]);
            sor(field2[y[i]]);
            rep(j, field[x[i]].size()) {
                int xt = x[i];
                int yt = field[x[i]][j];
                rep(k, field2[yt].size()) {
                    if (field2[yt][k] == xt)
                        continue;
                    if (binary_search(field2[y[i]].begin(), field2[y[i]].end(),
                                      field2[yt][k])) {

                    } else {
                        field2[y[i]].pb(field2[yt][k]);
                    }
                }
            }
        }
    }

    /* --------------------------------- */
    return 0;
}