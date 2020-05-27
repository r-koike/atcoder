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

int n, A, B, C, D, a[110], b[110], c[110], d[110];
int fourth[110];

bool dfs(int i, int ai, int bi, int ci, int di) {
    if (i == n)
        return true;

    int ac = (ai >= A) ? 0 : a[ai];
    int bc = (bi >= B) ? 0 : b[bi];
    int cc = (ci >= C) ? 0 : c[ci];
    int dc = (di >= D) ? 0 : d[di];

    rep1(j, 3) {
        if (ac == j || bc == j || cc == j || dc == j) {
            continue;
        } else {
            return false;
        }
    }

    if (ac == 0) {
        if (dfs(i + 1, ai, bi + 1, ci + 1, di + 1)) {
            fourth[i] = 0;
            return true;
        }
    } else if (bc == 0) {
        if (dfs(i + 1, ai + 1, bi, ci + 1, di + 1)) {
            fourth[i] = 1;
            return true;
        }
    } else if (cc == 0) {
        if (dfs(i + 1, ai + 1, bi + 1, ci, di + 1)) {
            fourth[i] = 2;
            return true;
        }
    } else if (dc == 0) {
        if (dfs(i + 1, ai + 1, bi + 1, ci + 1, di)) {
            fourth[i] = 3;
            return true;
        }
    }

    if (ac == bc || ac == cc || ac == dc) {
        if (dfs(i + 1, ai, bi + 1, ci + 1, di + 1)) {
            fourth[i] = 0;
            return true;
        }
    }
    if (bc == ac || bc == cc || bc == dc) {
        if (dfs(i + 1, ai + 1, bi, ci + 1, di + 1)) {
            fourth[i] = 1;
            return true;
        }
    }
    if (cc == ac || cc == bc || cc == dc) {
        if (dfs(i + 1, ai + 1, bi + 1, ci, di + 1)) {
            fourth[i] = 2;
            return true;
        }
    }
    if (dc == ac || dc == bc || dc == cc) {
        if (dfs(i + 1, ai + 1, bi + 1, ci + 1, di)) {
            fourth[i] = 3;
            return true;
        }
    }

    return false;
}

int main() {
    scanf("%d%d%d%d%d", &n, &A, &B, &C, &D);
    rep(i, A) scanf("%d", &a[i]);
    rep(i, B) scanf("%d", &b[i]);
    rep(i, C) scanf("%d", &c[i]);
    rep(i, D) scanf("%d", &d[i]);

    if (n * 3 != A + B + C + D) {
        printf("No\n");
        return 0;
    }

    if (dfs(0, 0, 0, 0, 0)) {
        printf("Yes\n");
        rep(i, n) {
            printf("%d\n", fourth[i] + 1);
        }
    } else {
        printf("No\n");
    }

    /* --------------------------------- */
    return 0;
}