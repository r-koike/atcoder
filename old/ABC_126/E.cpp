/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2019.05.19 21:58:11
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

// ===================### Union-Findの実装 ###=================== //
const int UF_SIZE = 100010;
int cnt = 0;

int par[UF_SIZE]; // 親
int siz[UF_SIZE]; // 木の深さ

// n要素で初期化
void init(int n) {
    for (int i = 0; i < n; i++) {
        par[i] = i;
        siz[i] = 1;
    }
}
// 木の根を求める
int find(int x) {
    if (par[x] == x) {
        return x;
    } else {
        return par[x] = find(par[x]);
    }
}
// xとyの属する集合を併合
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
        return;

    cnt++;
    if (siz[x] < siz[y]) {
        par[x] = y;
        siz[y] += siz[x];
    } else {
        par[y] = x;
        siz[x] += siz[y];
    }
}
// xとyが同じ集合に属するか否か
bool same(int x, int y) {
    return find(x) == find(y);
}
// xが属する集合の要素数
int size(int x) {
    return siz[find(x)];
}

bool dp[100010];

int main() {
    int n, m;
    int x, y, z;
    scanf("%d%d", &n, &m);
    rep1(i, n) dp[i] = false;

    init(n);

    rep(i, m) {
        scanf("%d%d%d", &x, &y, &z);
        unite(x, y);
    }
    printf("%d\n", n - cnt);

    /* --------------------------------- */
    return 0;
}