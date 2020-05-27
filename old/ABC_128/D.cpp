/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2019.05.26 20:48:33
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
    int n, k;
    int v[55];
    scanf("%d%d", &n, &k);
    rep(i, n) scanf("%d", &v[i]);

    int ret = 0;

    // iは取り出す回数
    rep(i, k + 1) {
        // pは戻す回数
        int p = k - i;
        if (i > n) {
            break;
        }
        // lは左端から取る個数
        rep(l, i + 1) {
            // rは右端から取る個数
            int r = i - l;
            vector<int> neg, pog;
            neg = {};
            pog = {};
            rep(j, l) {
                if (v[j] < 0) {
                    neg.pb(v[j]);
                } else {
                    pog.pb(v[j]);
                }
            }
            rep(j, r) {
                if (v[n - 1 - j] < 0) {
                    neg.pb(v[n - 1 - j]);
                } else {
                    pog.pb(v[n - 1 - j]);
                }
            }
            sor(neg);
            rev(neg);
            rep(j, p) {
                if (neg.empty()) {
                    break;
                }
                neg.pop_back();
            }
            int sum = 0;
            rep(j, neg.size()) {
                sum += neg[j];
            }
            rep(j, pog.size()) {
                sum += pog[j];
            }
            ret = max(ret, sum);
        }
    }

    printf("%d\n", ret);

    /* --------------------------------- */
    return 0;
}