/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2019.05.19 20:58:39
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
    double n, k;
    scanf("%lf%lf", &n, &k);

    int i = 0;
    int pre = n + 1;
    int now = k;
    int cnt = 0;
    double ret = 0;
    while (1) {
        if (pre - now <= 0) {
            i++;
            now = (now + 1) / 2;
            continue;
        } else {
            cnt = pre - now;
            ret += (double)cnt / n * (1 / (double)(1 << i));

            pre = now;
            i++;
            if (now == 1)
                break;
            cout << "i:" << i << ret << endl;
            now = (now + 1) / 2;
        }
    }

    printf("%lf\n", ret);

    /* --------------------------------- */
    return 0;
}