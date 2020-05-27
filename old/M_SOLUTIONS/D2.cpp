/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2019.06.01 20:59:45
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

vector<int> G[10005];
vector<int> c;
int ret[10005];
int ci = 0;
ll sum = 0;

void dfs(int pre, int from) {
    int cnt = 0;
    rep(i, G[from].size()) {
        if (ret[G[from][i]] < 0) {
            cnt++;
        }
    }
    if (cnt <= 1) {
        ret[from] = c[ci];
        ci++;
    }

    rep(i, G[from].size()) {
        if (G[from][i] != pre && ret[G[from][i]] < 0) {
            dfs(from, G[from][i]);
        }
    }
}

void dfs1(int pre, int from) {
    rep(i, G[from].size()) {
        if (G[from][i] != pre) {
            sum += min(ret[from], ret[G[from][i]]);
            dfs1(from, G[from][i]);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int aa, bb, cc;
    rep(i, n - 1) {
        scanf("%d%d", &aa, &bb);
        G[aa - 1].pb(bb - 1);
        G[bb - 1].pb(aa - 1);
    }
    rep(i, n) {
        scanf("%d", &cc);
        c.pb(cc);
    }
    rep(i, n) {
        ret[i] = -1;
    }

    sor(c);

    while (ci < n) {
        rep(i, n) {
            if (ci >= n)
                break;
            if (ret[i] < 0) {
                dfs(-1, i);
            }
        }
    }

    dfs1(-1, 0);

    printf("%lld\n", sum);

    rep(i, n) {
        if (i != 0)
            printf(" ");
        printf("%d", ret[i]);
    }

    /* --------------------------------- */
    return 0;
}