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

//#define int long long

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

const int INF = 100000000;
const int M = 100000000;
const int dir_4[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int dir_8[8][2] = {{1, 0},  {1, 1},   {0, 1},  {-1, 1},
                         {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

/* ------------------------------------- */

// dp[i][j]は、Aの後ろからi個、Bの後ろからj個までがある場合のすぬけ君の最大値
int dp[1010][1010];

int main() {
    int A, B, a[1010], b[1010];
    scanf("%d%d", &A, &B);
    rep(i, A) scanf("%d", &a[i]);
    rep(i, B) scanf("%d", &b[i]);

    dp[0][0] = 0;
    rep(i, A + 1) rep(j, B + 1) {
        if (i == 0 && j > 0) {
            if ((i + j + A + B) % 2 == 0) {
                dp[i][j] = dp[i][j - 1] + b[B - j];
            } else {
                dp[i][j] = dp[i][j - 1];
            }
        } else if (i > 0 && j == 0) {
            if ((i + j + A + B) % 2 == 0) {
                dp[i][j] = dp[i - 1][j] + a[A - i];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        } else if (i == 0 && j == 0) {
            dp[i][j] = 0;
        } else {
            if ((i + j + A + B) % 2 == 0) {
                dp[i][j] =
                    max(dp[i - 1][j] + a[A - i], dp[i][j - 1] + b[B - j]);
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    rep(i, A + 1) rep(j, B + 1) cout << i << "," << j << "," << dp[i][j]
                                     << endl;

    printf("%d", dp[A][B]);
    /* --------------------------------- */
    printf("\n");
    return 0;
}