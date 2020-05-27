/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2019.07.14 20:52:00
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
int n, m;
vector<int> G[100010];
vector<int> Gn[100010];
int cost[100010];
bool check[100010];

void dfs(int i, int from) {
    // printf("dfs i:%d from:%d\n", i + 1, from + 1);
    int moto;
    rep(j, 2) {
        if (G[i][j] != from) {
            moto = G[i][j];
            break;
        }
    }
    if (cost[i] % 2 == 1) {
        cost[i]++;
        Gn[i].pb(moto);
    } else {
        cost[moto]++;
        Gn[moto].pb(i);
    }
    check[i] = true;
    if (G[moto].size() == 2) {
        dfs(moto, i);
    }
}

int main() {
    int aa, bb;
    scanf("%d%d", &n, &m);
    rep(i, n) {
        scanf("%d%d", &aa, &bb);
        G[aa - 1].pb(bb - 1);
        G[bb - 1].pb(aa - 1);
    }

    if (m % 2 == 1) {
        printf("%d\n", -1);
        return 0;
    }

    rep(i, n) {
        cost[i] = 0;
        check[i] = false;
    }

    rep(i, n) {
        if (check[i]) {
            continue;
        }
        if (G[i].size() == 1) {
            dfs(i, -1);
        }
    }

    rep(i, n) {
        if (check[i]) {
            continue;
        }
        rep(j, G[i].size()) {
            int to = G[i][j];
            if (check[to]) {
                continue;
            }
            if (cost[i] % 2 == 1 || (((G[i].size() - i) % 2 == 0) && cost[i] % 2 == 0)) {
                cost[i]++;
                Gn[i].pb(to);
            } else {
                cost[to]++;
                Gn[to].pb(i);
            }
        }
        check[i] = true;
    }

    bool b = true;
    rep(i, n) {
        if (cost[i] % 2 == 1) {
            b = false;
            break;
        }
    }

    if (!b) {
        printf("%d\n", -1);
    } else {
        rep(i, n) {
            rep(j, Gn[i].size()) {
                printf("%d %d\n", i + 1, Gn[i][j] + 1);
            }
        }
    }
    // cout << "--" << endl;
    // rep(i, n) {
    //     printf("%d\n", cost[i]);
    // }

    /* --------------------------------- */
    return 0;
}