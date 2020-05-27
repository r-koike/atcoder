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
int rets[200010];
int gcd(int a, int b) {
    if (a % b == 0) {
        return (b);
    } else {
        return (gcd(b, a % b));
    }
}

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

    int c1 = a[0];
    rep1(i, n - 1) {
        c1 = max(gcd(c1, a[i]), gcd(c1, b[i]));
    }
    int c2 = b[0];
    rep1(i, n - 1) {
        c2 = max(gcd(c2, a[i]), gcd(c2, b[i]));
    }

    printf("%d\n", max(c1, c2));

    /* --------------------------------- */
    return 0;
}