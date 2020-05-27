/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2019.05.10 12:09:11
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
#define rep2(i, x) for (int i = 2; i <= x; i++)
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
const int N = 200;

bool dp[N + 1];
int cnt[N + 1];

int main() {
    int n;
    scanf("%d", &n);
    rep2(i, n) dp[i] = true;

    int sqn = sqrt(n);
    rep2(i, sqn) {
        if (!dp[i])
            continue;
        for (int j = i * i; j <= n; j += i)
            dp[j] = false;
    }

    vector<int> primes;
    rep2(i, n) {
        if (dp[i]) {
            primes.pb(i);
        }
    }

    /* --------------------------------- */

    int pl = primes.size();
    rep2(i, n) {
        int t = i;
        rep(j, pl) {
            int p = primes[j];
            if (t == 1)
                break;
            while (t % p == 0) {
                t /= p;
                cnt[p]++;
            }
        }
    }

    // rep2(i, n) {
    //     printf("%d\n", cnt[i]);
    // }

    int over74 = 0;
    int over24 = 0;
    int over14 = 0;
    int over4 = 0;
    int over2 = 0;

    rep2(i, n) {
        int cn = cnt[i];
        if (cn < 2)
            continue;
        if (cn >= 74)
            over74++;
        if (cn >= 24)
            over24++;
        if (cn >= 14)
            over14++;
        if (cn >= 4)
            over4++;
        if (cn >= 2)
            over2++;
    }

    int ret = 0;

    ret += over74;
    if (over4 > 1) {
        ret += over14 * (over4 - 1);
    }
    if (over2 > 1) {
        ret += over24 * (over2 - 1);
    }
    if (over4 > 1 && over2 > 2) {
        ret += over4 * (over4 - 1) / 2 * (over2 - 2);
    }

    printf("%d\n", ret);

    /* --------------------------------- */
    return 0;
}