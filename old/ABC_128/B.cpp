/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2019.05.26 20:48:27
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
    string s[110];
    int p[110];
    cin >> n;
    rep(i, n) {
        cin >> s[i] >> p[i];
    }
    vector<pair<int, pair<string, int>>> vec;
    rep(i, n) {
        vec.pb(mp(i + 1, mp(s[i], p[i])));
    }
    sort(vec.begin(), vec.end(),
         [](const pair<int, pair<string, int>> a, const pair<int, pair<string, int>> b) {
             string as = a.sc.fr;
             string bs = b.sc.fr;
             int ap = a.sc.sc;
             int bp = b.sc.sc;
             if (as != bs)
                 return as < bs;
             else
                 return ap > bp;
         });
    rep(i, n) {
        cout << vec[i].fr << '\n';
    }

    /* --------------------------------- */
    return 0;
}