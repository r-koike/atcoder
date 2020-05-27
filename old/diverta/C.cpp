/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2019.05.11 20:50:43
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
    string s[10010];
    cin >> n;
    rep(i, n) cin >> s[i];

    int afin = 0;
    int bsta = 0;
    int ba = 0;
    int ret = 0;
    rep(i, n) {
        string st = s[i];
        int sl = st.size();
        bool isBsta = false;
        bool preA = false;
        rep(j, sl) {
            if (j == 0 && st[j] == 'B') {
                bsta++;
                isBsta = true;
            } else if (j == sl - 1 && st[j] == 'A' && !isBsta) {
                afin++;
            } else if (j == sl - 1 && st[j] == 'A' && isBsta) {
                bsta--;
                ba++;
            }

            if (st[j] == 'A') {
                preA = true;
            } else if (st[j] == 'B' && preA) {
                preA = false;
                ret++;
            } else {
                preA = false;
            }
        }
    }

    if (bsta == 0 && afin == 0) {
        ret += ba > 0 ? ba - 1 : 0;
    } else if (bsta == afin) {
        ret += bsta;
        ret += ba;
    } else if (bsta > afin) {
        if (ba + afin >= bsta) {
            ret += bsta;
            ret += ba + afin - bsta;
        } else {
            ret += ba + afin;
        }
    } else if (bsta < afin) {
        if (ba + bsta >= afin) {
            ret += afin;
            ret += ba + bsta - afin;
        } else {
            ret += ba + bsta;
        }
    }

    cout << ret << '\n';

    /* --------------------------------- */
    return 0;
}