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
const int M = 9973;
const int dir_4[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int dir_8[8][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

/* ------------------------------------- */

int main() {
    int a[30];
    rep(i, 26) scanf("%d", &a[i]);
    int ret[10];
    string rets;
    ret[0] = a[0] - a[1];
    ret[1] = a[2] + a[3];
    ret[2] = max(0, a[5] - a[4] + 1);
    ret[3] = (a[6] + a[7] + a[8]) / 3 + 1;
    switch (a[9]) {
    case 1:
        rets = "a";
        break;
    case 2:
        rets = "aa";
        break;
    case 3:
        rets = "aaa";
        break;
    case 4:
        rets = "aaai";
        break;
    case 5:
        rets = "aaaji";
        break;
    case 6:
        rets = "aabaji";
        break;
    case 7:
        rets = "agabaji";
        break;
    case 8:
        rets = "dagabaji";
        break;
    }
    int i = 0;
    int k = a[10];
    int l = a[11];
    int cnt = 0;
    while (1) {
        i++;
        if (i % 59 != k || i % 61 != l) {
            continue;
        }
        cnt++;
        if (cnt == a[12]) {
            break;
        }
    }
    int kanzen = 0;
    if (abs(i - 6) >= a[13]) {
        kanzen = 6;
    } else if (abs(i - 28) >= a[13]) {
        kanzen = 28;
    } else if (abs(i - 496) >= a[13]) {
        kanzen = 496;
    } else if (abs(i - 8128) >= a[13]) {
        kanzen = 8128;
    } else if (abs(i - 33550336) >= a[13]) {
        kanzen = 33550336;
    }
    ret[5] = min(i, kanzen);
    ret[6] = max(i, kanzen);
    ret[7] = (((a[14] + a[15] + a[16]) % M) * ((a[17] + a[18] + a[19]) % M) % M) *
             (((a[20] + a[21] + a[22]) % M) * ((a[23] + a[24] + a[25]) % M) % M) % M;
    printf("%d\n", ret[0]);
    printf("%d\n", ret[1]);
    printf("%d\n", ret[2]);
    printf("%d\n", ret[3]);
    cout << rets << '\n';
    printf("%d\n", ret[5]);
    printf("%d\n", ret[6]);
    printf("%d\n", ret[7]);

    /* --------------------------------- */
    return 0;
}