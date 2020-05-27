/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2019.07.21 20:55:22
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
vector<int> vec[200010];
int a[200010];
vector<int> ret;

int main() {
    int n;
    ll k;
    int att;

    scanf("%d", &n);
    scanf("%lld", &k);

    rep(i, n) {
        scanf("%d", &att);
        vec[att].pb(i);
        a[i] = att;
    }

    int at = a[0];
    int i = 0;
    int j = 0;
    int eb = false;
    while (1) {
        auto ite = ub(vec[at], j);
        if (ite == vec[at].end()) {
            // 1巡
            ite = vec[at].begin();
            i++;
            if (i >= k) {
                // j番目からn-1番目(最後まで普通にやる)
                eb = false;
                break;
            }
        }
        j = *ite + 1;
        at = a[j];
        if (j == n) {
            // 全消し
            eb = true;
            break;
        }
    }
    // printf("%d\n", i);

    if (eb) {
        int nk = k % (i + 1);
        // nk回普通にやる
        int j = 0;
        int m = 0;
        at = a[j];
        while (m < nk) {
            // printf("%d\n", j);
            auto ite = ub(vec[at], j);
            if (ite == vec[at].end()) {
                // 1巡
                ite = vec[at].begin();
                m++;
                // printf("a%d\n", j);
                if (m >= nk) {
                    // 最後の詰め
                    for (int l = j; l < n; l++) {
                        auto ite = ub(vec[a[l]], l);
                        if (ite == vec[a[l]].end()) {
                            ret.pb(a[l]);
                        } else {
                            l = *ite;
                        }
                    }
                }
            }
            j = *ite + 1;
            at = a[j];
        }
    } else {
        // printf("aaaaa\n");
        for (int l = j; l < n; l++) {
            auto ite = ub(vec[a[l]], l);
            if (ite == vec[a[l]].end()) {
                ret.pb(a[l]);
            } else {
                l = *ite;
            }
        }
    }

    rep(l, ret.size()) {
        if (l != 0) {
            printf(" ");
        }
        printf("%d", ret[l]);
    }
    printf("\n");

    // disp_vec(ret);

    /* --------------------------------- */
    return 0;
}