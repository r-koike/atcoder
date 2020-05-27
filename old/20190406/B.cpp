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

int main() {
    int a[5];
    scanf("%d%d%d%d%d", &a[0], &a[1], &a[2], &a[3], &a[4]);
    int m = 20;
    rep(i, 5) {
        if (a[i] % 10 != 0 && m > a[i] % 10) {
            m = a[i] % 10;
        }
    }
    if (m == 20) {
        printf("%d", a[0] + a[1] + a[2] + a[3] + a[4]);
        printf("\n");
        return 0;
    }
    int ret = 0;
    rep(i, 5) {
        if (a[i] % 10 == 0) {
            ret += a[i];
        } else {
            ret += ((a[i] / 10) + 1) * 10;
        }
    }
    ret -= (10 - m);

    printf("%d", ret);

    /* --------------------------------- */
    printf("\n");
    return 0;
}