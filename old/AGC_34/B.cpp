/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2019.06.02 20:56:07
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
string s;
int ret = 0;

int main() {
    cin >> s;
    int sl = s.size();

    int loop = 0;
    int preloop = -1;
    for (int i = sl - 1; i > 1; i++) {
        switch (loop % 3) {
        case 0:
            if (s[i] == 'C') {
                loop++;
            }
        case 1:
            if (s[i] == 'B') {
                loop++;
            }
        case 2:
            if (s[i] == 'A') {
                loop++;
            }
        }
        if (loop > 2 && loop == preloop) {
            int cnt = loop / 3;
            ret += cnt * 2 - 1;
            rep(j, cnt) {
                s[i + loop - j * 3 - 2] = 'B';
                s[i + loop - j * 3 - 1] = 'C';
                s[i + loop - j * 3] = 'A';
            }
        }
        if (s[i] == 'C') {
        }
        if (s[i - 2] == 'A' && s[i - 1] == 'B' && s[i] == 'C') {
            ret++;
            s[i - 2] = 'B';
            s[i - 1] = 'C';
            s[i] = 'A';
        }
    }

    cout << ret << '\n';

    /* --------------------------------- */
    return 0;
}