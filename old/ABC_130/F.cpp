/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2019.06.16 22:18:25
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

const int INF = 100000010;
const int M = 100000000;
const int dir_4[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int dir_8[8][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

/* ------------------------------------- */

int main() {
    int n;
    int x, y;
    char d;
    scanf("%d", &n);

    int xma0 = -INF;
    int xma1 = -INF;
    int xma2 = -INF;
    int xmi0 = INF;
    int xmi1 = INF;
    int xmi2 = INF;

    rep(i, n) {
        scanf("%d%d %c", &x, &y, &d);
        if (d == 'U' || d == 'D') {
            xma0 = max(xma0, x);
            xmi0 = min(xmi0, x);
        } else if (d == 'R') {
            xma2 = max(xma2, x);
            xmi2 = min(xmi2, x);
        } else if (d == 'L') {
            xma1 = max(xma1, x);
            xmi1 = min(xmi1, x);
        }
    }

    double tma01 = xma1 - xma0;
    double tma12 = (xma1 - xma2) / 2.0;
    double tma20 = xma0 - xma2;
    double tmi01 = xmi1 - xmi0;
    double tmi12 = (xmi1 - xmi2) / 2.0;
    double tmi20 = xmi0 - xmi2;

    /* --------------------------------- */
    return 0;
}