/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2019.06.15 20:56:28
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
    int a[100005];
    vector<int> neg;
    vector<int> pog;
    scanf("%d", &n);
    rep(i, n) {
        scanf("%d", &a[i]);
        if (a[i] < 0) {
            neg.pb(a[i]);
        } else {
            pog.pb(a[i]);
        }
    }

    sor(neg);
    sor(pog);

    int negl;
    if (0 < neg.size() && neg.size() < n) {
        negl = neg.size();
    } else if (neg.size() == 0) {
        negl = 1;
    } else {
        negl = n - 1;
    }
    int m = 0;
    int negcnt = 0;

    vector<int> retneg;
    vector<int> retpog;

    rep(i, neg.size()) {
        if (negcnt < negl) {
            negcnt++;
            retneg.pb(neg[i]);
            m += -neg[i];
        } else {
            retpog.pb(neg[i]);
            m += neg[i];
        }
    }
    rep(i, pog.size()) {
        if (negcnt < negl) {
            negcnt++;
            retneg.pb(pog[i]);
            m += -pog[i];
        } else {
            retpog.pb(pog[i]);
            m += pog[i];
        }
    }

    printf("%d\n", m);

    vector<P> ret;

    negcnt = 0;
    int pogid = 0;
    int negid = 0;
    bool flip = false;
    rep(i, n - 1) {
        // 残り回数
        int nokori = n - 1 - i;
        // 残りマイナス数
        int negnokori = negl - negid;
        // 残り＋数
        int pognokori = (n - negl) - pogid;

        if ((negnokori == 0 && flip) || (pognokori == 0 && !flip) ||
            (nokori == negnokori && !flip) || (nokori == pognokori && flip)) {
            if (flip) {
                m = retpog[pogid] + m;
                ret.pb(P(m, retpog[pogid]));
                pogid++;
            } else {
                m = m + retneg[negid];
                ret.pb(P(m, retneg[negid]));
                negid++;
            }
        } else {
            if (flip) {
                m = retneg[negid] - m;
                ret.pb(P(retneg[negid], m));
                negid++;
            } else {
                m = retpog[pogid] - m;
                ret.pb(P(retpog[pogid], m));
                pogid++;
            }
            flip = !flip;
        }
    }

    rrep(i, n - 1) {
        printf("%d %d\n", ret[i].fr, ret[i].sc);
    }

    /* --------------------------------- */
    return 0;
}