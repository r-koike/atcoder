/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2019.12.29 19:57:37
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

// ===================### 素数取得 ###=================== //
bool primeDp[1000000000];
vector<int> getPrimes(int n) {
    int u = n + 32;
    double lu = log(u);
    vector<int> ret((int)(u / lu + u / lu / lu * 1.5));

    for (int i = 2; i <= n; i++)
        primeDp[i] = true;
    int sqn = sqrt(n);
    for (int i = 2; i <= sqn; i++) {
        if (!primeDp[i])
            continue;
        for (int j = i * i; j <= n; j += i)
            primeDp[j] = false;
    }
    int idx = 0;
    for (int i = 2; i <= n; i++) {
        if (primeDp[i]) {
            ret[idx] = i;
            idx++;
        }
    }
    return vector<int>(ret.begin(), ret.begin() + idx);
}

int main() {
    vector<int> primes = getPrimes(1000000);
    int x;
    scanf("%d", &x);

    auto iter = lb(primes, x);

    printf("%d\n", *iter);

    /* --------------------------------- */
    return 0;
}