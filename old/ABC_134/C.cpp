/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2019.09.07 16:03:58
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

int main() {
    vector<P> vec;
    int n, a;
    scanf("%d", &n);
    rep(i, n) {
        scanf("%d", &a);
        vec.pb(mp(i, a));
    }

    sort(vec.begin(), vec.end(), [](const P a, const P b) {
        if (a.sc != b.sc)
            return a.sc > b.sc;
        else
            return a.fr > b.fr;
    });

    int mi, ma, si, sa;
    mi = vec[0].fr;
    ma = vec[0].sc;
    si = vec[1].fr;
    sa = vec[1].sc;

    rep(i, n) {
        if (i == mi) {
            printf("%d\n", sa);
        } else {
            printf("%d\n", ma);
        }
    }

    /* --------------------------------- */
    return 0;
}