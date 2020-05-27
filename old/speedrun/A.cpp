/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2019.05.25 13:52:54
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
    int n;
    int at, bt;
    scanf("%d", &n);
    vector<int> a(n), b(n);
    rep(i, n) {
        scanf("%d%d", &at, &bt);
        a[i] = at;
        b[i] = bt;
    }
    vector<P> p(n);
    rep(i, n) {
        int m1 = min(a[i], b[i]);
        int m2 = max(a[i], b[i]);
        p.pb(P(m1, m2));
    }
    cout << p.size() << endl;
    p.erase(unique(p.begin(), p.end(),
                   [](const P a, const P b) { return a.fr == b.fr && a.sc == b.sc; }),
            p.end());
    cout << p.size() << endl;
    int ret = p.size();
    printf("%d\n", ret);

    /* --------------------------------- */
    return 0;
}