/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2019.07.14 20:52:08
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

vector<P> ret;

int main() {
    int n;
    scanf("%d", &n);

    int te = 1;
    while (1) {
        if (te - 1 > n) {
            break;
        } else {
            te *= 2;
        }
    }
    te /= 2;
    te--;

    int len = n - te;
    int b = len % 4;

    // 判定
    if (n <= 2 || len == 1) {
        printf("No\n");
        return 0;
    }

    // 基本
    rep1(i, te - 1) {
        ret.pb(P(i, i + 1));
        ret.pb(P(i + n, i + n + 1));
    }
    ret.pb(P(te, n + 1));

    if (len > 0) {
        if (len == 3) {
            ret.pb(P(te + 1, te + 2));
            ret.pb(P(te + 2, 1));
            ret.pb(P(te + 1 + n, 1));
            ret.pb(P(te + 1 + n, te + 2 + n));
            ret.pb(P(te + 2, te + 3));
            ret.pb(P(2, te + 3 + n));

        } else if (b == 2) {
            // はさむ
            rep1(i, len - 1) {
                ret.pb(P(te + i, te + i + 1));
                ret.pb(P(te + i + n, te + i + 1 + n));
            }
            ret.pb(P(te + len, 1));
            ret.pb(P(1, te + 1 + n));
        } else if (b == 0) {
            // そのままくっつける
            rep1(i, len - 1) {
                ret.pb(P(te + i, te + i + 1));
                ret.pb(P(te + i + n, te + i + 1 + n));
            }
            ret.pb(P(te + len, te + 1 + n));
            ret.pb(P(te + len + n, 1));
        } else if (b == 1) {
            // むりやり
            rep1(i, len - 2) {
                ret.pb(P(te + i, te + i + 1));
                ret.pb(P(te + i + n, te + i + 1 + n));
            }
            ret.pb(P(te + len - 1, te + 1 + n));
            int a = (te + 1) ^ n;
            ret.pb(P(n, a));
            ret.pb(P(a, te + 1));
            ret.pb(P(te + 1, 2 * n));
        } else if (b == 3) {
            rep1(i, len - 4) {
                ret.pb(P(te + i, te + i + 1));
                ret.pb(P(te + i + n, te + i + 1 + n));
            }
            ret.pb(P(te + len - 3, te + 1 + n));
            int a = te + 1;
            a ^= (n);
            a ^= (n - 1);
            a ^= (n - 2);
            ret.pb(P(n - 2, n - 1));
            ret.pb(P(n - 1, n));
            ret.pb(P(n, a));
            ret.pb(P(a, te + 1));
            ret.pb(P(te + 1, 2 * n - 2));
            ret.pb(P(2 * n - 2, 2 * n - 1));
            ret.pb(P(2 * n - 1, 2 * n));
        }
    }

    printf("Yes\n");
    rep(i, ret.size()) {
        printf("%d %d\n", ret[i].fr, ret[i].sc);
    }

    /* --------------------------------- */
    return 0;
}