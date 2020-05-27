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

vector<int> Gnow[10005];
vector<int> Gnext[10005];
vector<int> c;
int ret[10005];
int ci = 0;
int ns = 0;

void dfs(int pre, int from, const vector<int> G[10005]) {
    bool isHa = false;
    if (G[from].size() == 1) {
        ret[from] = c[ci];
        ci++;
        isHa = true;
    }
    rep(i, G[from].size()) {
        if (G[from][i] != pre) {
            dfs(from, G[from][i], G);
            if (!isHa) {
                ns = G[from][i];
                Gnext[from].pb(G[from][i]);
                Gnext[G[from][i]].pb(from);
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int aa, bb, cc;
    rep(i, n - 1) {
        scanf("%d%d", &aa, &bb);
        Gnow[aa - 1].pb(bb - 1);
        Gnow[bb - 1].pb(aa - 1);
    }
    rep(i, n) {
        scanf("%d", &cc);
        c.pb(cc);
    }

    sor(c);

    while (ci < n) {
        cout << "ci:" << ci << endl;

        rep(i, n) {
            cout << i << ": ";
            disp_vec(Gnow[i]);
            cout << Gnow[i].size() << endl;
        }
        rep(i, n) {
            Gnext[i] = {};
        }

        dfs(-1, ns, Gnow);

        rep(i, n) {
            Gnow[i] = {};
            Gnow[i] = Gnext[i];
        }
    }

    rep(i, n) {
        if (i != 0)
            printf(" ");
        printf("%d", ret[i]);
    }

    /* --------------------------------- */
    return 0;
}