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
const int dir_8[8][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

/* ------------------------------------- */

char s[100010];
int vl[100010], vr[100010];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    scanf("%s", &s);

    int cntl = 0;
    int cntr = 0;
    for (int i = -1; i < n + 1; i++) {
        if (i == -1) {
            vl[cntl] = -1;
            cntl++;
            if (s[0] == '0') {
                vr[cntr] = -1;
                cntr++;
            }
            continue;
        }
        if (i == n) {
            vr[cntr] = i;
            cntr++;
            if (s[i - 1] == '0') {
                vl[cntl] = i;
                cntl++;
            }
            continue;
        }
        if (s[i] == '1' && i < n - 1 ? (s[i + 1] == '0') : false) {
            vr[cntr] = i;
            cntr++;
        }
        if (s[i] == '1' && i > 0 ? (s[i - 1] == '0') : false) {
            vl[cntl] = i;
            cntl++;
        }
    }
    int vs = cntl;

    if (vs - k <= 1) {
        printf("%d\n", n);
        return 0;
    }
    int ret = 0;
    rep(i, vs - k) {
        if (i == 0) {
            ret = max(ret, vr[i + k] - vl[i]);
        } else if (i == vs - k - 1) {
            ret = max(ret, vr[i + k] - vl[i]);
        } else {
            ret = max(ret, vr[i + k] - vl[i] + 1);
        }
    }

    printf("%d\n", ret);

    /* --------------------------------- */
    return 0;
}