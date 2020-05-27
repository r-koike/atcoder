/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2019.05.19 20:58:34
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
    string s;
    cin >> s;

    int c1, c2, c3, c4;
    c1 = s[0] - '0';
    c2 = s[1] - '0';
    c3 = s[2] - '0';
    c4 = s[3] - '0';

    int n1 = c1 * 10 + c2;
    int n2 = c3 * 10 + c4;

    bool m1 = (n1 >= 1 && n1 <= 12);
    bool y1 = true;
    bool m2 = (n2 >= 1 && n2 <= 12);
    bool y2 = true;

    if (m1 && m2) {
        cout << "AMBIGUOUS";
    } else if (m1 && !m2) {
        cout << "MMYY";
    } else if (!m1 && m2) {
        cout << "YYMM";
    } else if (!m1 && !m2) {
        cout << "NA";
    }

    cout << '\n';

    /* --------------------------------- */
    return 0;
}