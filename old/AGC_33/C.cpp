/**
 * @brief : c++ code for AtCoder
 * @author: rk222
 * @created: 2019.05.04 20:58:05
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

int n, a[200010], b[200010];
vector<int> g[200010];
int maxlen = -1;
int maxs = -1;

void dfs(int s, int len, int from) {
    if (g[s].size() == 1 && len > 0) {
        if (len > maxlen) {
            maxs = s;
            maxlen = len;
        }
        return;
    } else {
        len++;
        rep(i, g[s].size()) {
            int to = g[s][i];
            if (to == from) {
                continue;
            }
            dfs(to, len, s);
        }
    }
    return;
}

int main() {
    scanf("%d", &n);
    rep(i, n - 1) scanf("%d%d", &a[i], &b[i]);
    rep(i, n - 1) {
        g[a[i] - 1].pb(b[i] - 1);
        g[b[i] - 1].pb(a[i] - 1);
    }

    dfs(0, 0, 0);
    dfs(maxs, 0, 0);

    maxlen++;
    if (maxlen % 3 == 2) {
        printf("Second\n");
    } else {
        printf("First\n");
    }

    /* --------------------------------- */
    return 0;
}