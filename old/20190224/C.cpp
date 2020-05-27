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

const int INF = 100000000;
const ll M = 1000000000;
const int dir_4[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int dir_8[8][2] = {{1, 0},  {1, 1},   {0, 1},  {-1, 1},
                         {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

/*----------------------------------------------/
/- char         : %c  | char *       : %s  | short        : %hd
/- int          : %d  | long         : %ld | long long    : %lld
/- unsigned short:%hu | unsigned int : %u  | unsigned long: %lu
/- u_long long  : %llu| (octal)      : %o  | (hexadecimal): %x
/- float        : %f  | double       : %lf |
/----------------------------------------------*/

/*----------------------------------------------/
/- INT_MAX, LONG_MAX   : 1<<15 = 2.1*pow(10, 9)       (= 2147483647)
/- UINT_MAX, ULONG_MAX : 1<<16 = 4.2*pow(10, 9)       (= 4294967295)
/- LLONG_MAX           : 1<<63 = 9.2*pow(10, 18)      (= 9223372036854775807)
/- ULLONG_MAX          : 1<<64 = 1.8*pow(10, 19)      (= 18446744073709551615)
/----------------------------------------------*/

int n, a, b, c, l[30];
int ret = INF;

int solve(int a, vector<int> v) {
    int sum = 0;
    int ret0 = 0;
    if (v.size() == 0) {
        return INF;
    }
    rep(i, v.size()) {
        ret0 += 10;
        sum += v[i];
    }
    ret0 -= 10;
    ret0 += abs(sum - a);
    return ret0;
}

void dfs(int i, int use[20]) {
    if (i == n) {
        vector<int> vs[4];
        rep(j, n) {
            if (use[j] == 0) {
                vs[0].pb(l[j]);
            } else if (use[j] == 1) {
                vs[1].pb(l[j]);
            } else if (use[j] == 2) {
                vs[2].pb(l[j]);
            } else if (use[j] == 3) {
                vs[3].pb(l[j]);
            }
        }
        int sum0 = 0;
        sum0 += solve(a, vs[1]);
        sum0 += solve(b, vs[2]);
        sum0 += solve(c, vs[3]);
        ret = min(sum0, ret);
        return;
    }

    use[i] = 0;
    dfs(i + 1, use);
    use[i] = 1;
    dfs(i + 1, use);
    use[i] = 2;
    dfs(i + 1, use);
    use[i] = 3;
    dfs(i + 1, use);

    return;
}

int main() {
    cin >> n >> a >> b >> c;
    rep(i, n) cin >> l[i];
    int u[20];
    dfs(0, u);

    cout << ret;

    /* ====================================== */
    cout << endl;
    return 0;
}