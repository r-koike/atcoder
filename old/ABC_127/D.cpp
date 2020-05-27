/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2019.05.25 20:44:00
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
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> a(n);
    vector<P> p(m);
    int at, bt, ct;
    rep(i, n) {
        scanf("%d", &at);
        a[i] = at;
    }
    rep(i, m) {
        scanf("%d%d", &bt, &ct);
        p[i] = P(bt, ct);
    }

    sor(a);
    sort(p.begin(), p.end(), [](const P b, const P c) {
        if (b.sc != c.sc)
            return b.sc > c.sc;
        else
            return b.fr > c.fr;
    });
    int id = 0;
    int pl = p.size();
    bool bre = false;
    rep(i, pl) {
        P pc = p[i];
        int bb = pc.fr;
        int cc = pc.sc;
        rep(j, bb) {
            if (a[id] < cc) {
                a[id] = cc;
                id++;
                if (id >= n) {
                    bre = true;
                    break;
                }
            } else {
                bre = true;
                break;
            }
        }
    }
    ll ret = 0;
    rep(i, n) {
        ret += a[i];
    }
    printf("%lld\n", ret);

    /* --------------------------------- */
    return 0;
}