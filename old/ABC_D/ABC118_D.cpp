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
int dp[10010];
int ret[10010];
const int num[] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int main() {
    int n, m, a_[20];
    scanf("%d%d", &n, &m);
    rep(i, m) scanf("%d", &a_[i]);
    vector<int> a;
    rep(i, m) a.pb(a_[i]);
    sor(a);
    rev(a);

    dp[0] = 0;
    rep1(i, n) {
        dp[i] = -INF;
        rep(j, m) {
            int nu = num[a[j]];
            if (i - nu < 0)
                continue;
            dp[i] = max(dp[i], dp[i - nu] + 1);
        }
    }
    int keta = dp[n];
    int mat = n;
    rep(i, keta) {
        rep(j, m) {
            int nu = num[a[j]];
            if (mat - nu >= 0 && dp[mat - nu] == dp[mat] - 1) {
                ret[i] = a[j];
                mat -= nu;
                break;
            }
        }
    }
    rep(i, keta) {
        printf("%d", ret[i]);
    }

    printf("\n");

    /* --------------------------------- */
    return 0;
}