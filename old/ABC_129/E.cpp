/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2019.06.09 20:55:32
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
#define rep(i, x) for (ll i = 0; i < x; i++)
#define rep1(i, x) for (ll i = 1; i <= x; i++)
#define rrep(i, x) for (ll i = x - 1; i >= 0; i--)
#define rrep1(i, x) for (ll i = x; i > 0; i--)
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
const ll M = 1000000007;
const int dir_4[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int dir_8[8][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

/* ------------------------------------- */

string s;
ll p3[100010];
ll p2[100010];

int main() {
    p3[0] = 1LL;
    rep1(i, 100009) {
        p3[i] = (p3[i - 1] * 3LL) % M;
    }
    p2[0] = 1LL;
    rep1(i, 100009) {
        p2[i] = (p2[i - 1] * 2LL) % M;
    }

    cin >> s;
    ll sl = s.size();

    // 1文字目
    ll ret = (p3[sl - 1] + 2) % M;
    ll cnt = 1LL;
    rep1(i, sl - 1) {
        if (s[i] == '1') {
            ret = (ret + (p3[sl - i - 1] + 1) * p2[cnt]) % M;
            cnt++;
        }
    }

    cout << ret << "\n";

    /* --------------------------------- */
    return 0;
}