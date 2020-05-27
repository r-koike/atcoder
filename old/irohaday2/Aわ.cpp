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
int dp[5005][5005];

int main() {
    string s, t;
    cin >> s >> t;
    int sl = s.size();
    int tl = t.size();

    rep(i, sl) rep(j, tl) {
        if (i == 0 && j == 0) {
            if (s[i] == t[j]) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = 0;
            }
        } else if (i == 0) {
            if (s[i] == t[j]) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i][j - 1];
            }
        } else if (j == 0) {
            if (s[i] == t[j]) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        } else {
            if (s[i] == t[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i][j - 1]));
            }
        }
    }
    // rep(i, sl) rep(j, tl) {
    //     printf("i:%d j:%d dp:%d\n", i, j, dp[i][j]);
    // }
    printf("%d\n", dp[sl - 1][tl - 1] + 1);

    /* --------------------------------- */
    return 0;
}