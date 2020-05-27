/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2019.05.25 20:44:06
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
    int q;
    vector<P> p;
    vector<pair<int, ll>> rets;
    scanf("%d", &q);
    rep(i, q) {
        int queryType;
        scanf("%d", &queryType);
        if (queryType == 1) {
            int a, b;
            scanf("%d%d", &a, &b);
            p.pb(P(a, b));
        } else if (queryType == 2) {
            sort(p.begin(), p.end(), [](const P a, const P b) {
                if (a.fr != b.fr)
                    return a.fr < b.fr;
                else
                    return a.sc < b.sc;
            });

            int pl = p.size();
            int pid;
            ll ret;
            if (pl % 2 == 1) {
                pid = (pl + 1) / 2 - 1;
                ret = 0;
                rep(i, pl) {
                    if (i < pid) {
                        ret += p[i].sc + (p[pid].fr - p[i].fr);
                    } else if (i == pid) {
                        ret += p[i].sc;
                    } else {
                        ret += p[i].sc + (p[i].fr - p[pid].fr);
                    }
                }
            } else {
                pid = pl / 2 - 1;
                ret = 0;
                rep(i, pl) {
                    if (i < pid) {
                        ret += p[i].sc + (p[pid].fr - p[i].fr);
                    } else if (i == pid) {
                        ret += p[i].sc;
                    } else {
                        ret += p[i].sc + (p[i].fr - p[pid].fr);
                    }
                }
            }
            rets.pb(pair<int, ll>(p[pid].fr, ret));
        }
    }
    rep(i, rets.size()) {
        printf("%d %lld\n", rets[i].fr, rets[i].sc);
    }

    /* --------------------------------- */
    return 0;
}