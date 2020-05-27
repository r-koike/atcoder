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
int n, ml, md;
int al[10010], bl[10010], dl[10010];
int ad[10010], bd[10010], dd[10010];

int d[10010];

int main() {
    fill(d, d + n, INF);
    d[0] = 0;
    rep(k, n) {
        rep(i, n - 1) {
            if (d[i + 1] < INF)
                d[i] = min(d[i], d[i + 1]);
        }
        rep(i, ml) {
            if (d[al[i] - 1] < INF) {
                d[bl[i] - 1] = min(d[bl[i] - 1], d[al[i] - 1] + dl[i]);
            }
        }
        rep(i, md) {
            if (d[bd[i] - 1] < INF) {
                d[ad[i] - 1] = min(d[ad[i] - 1], d[bd[i] - 1] - dd[i]);
            }
        }
    }

    int ret = d[n - 1];
    if (d[0] < 0) {
        ret = -1;
    } else if (ret == INF) {
        ret = -2;
    }
    printf("%d\n", ret);

    /* --------------------------------- */
    return 0;
}