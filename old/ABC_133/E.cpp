/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2019.07.07 21:38:14
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
const ll M = 1000000007;
const int dir_4[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int dir_8[8][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

/* ------------------------------------- */

int n, k, aa, bb;
vector<int> G[100010];
int score[100010];
int dab[100010];

void dfs(int now) {
    // printf("%d\n", now);
    int mi = 0;
    rep(i, G[now].size()) {
        int to = G[now][i];
        if (score[to] == INF) {
            continue;
        }
        mi += dab[to];
    }
    rep(i, G[now].size()) {
        int to = G[now][i];
        dab[to]++;
    }
    score[now] = k - mi;

    rep(i, G[now].size()) {
        int to = G[now][i];
        if (score[to] == INF) {
            dfs(to);
        }
    }
}

int main() {
    scanf("%d%d", &n, &k);
    rep(i, n - 1) {
        scanf("%d%d", &aa, &bb);
        G[aa - 1].pb(bb - 1);
        G[bb - 1].pb(aa - 1);
    }
    rep(i, n) {
        dab[i] = 1;
        score[i] = INF;
    }

    dfs(0);
    ll ret = 1LL;
    rep(i, n) {
        if (score[i] <= 0) {
            ret = 0;
        }
        ret = (ret * (ll)score[i]) % M;
    }
    printf("%lld\n", ret);

    /* --------------------------------- */
    return 0;
}