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
    int n, w[60];
    scanf("%d", &n);
    rep(i, n) scanf("%d", &w[i]);
    vector<int> v;
    rep(i, n) {
        if (v.size() == 0) {
            v.pb(w[i]);
            continue;
        }
        int W = INF, Wid = -1;
        rep(j, v.size()) {
            if (w[i] <= v[j] && v[j] < W) {
                W = v[j];
                Wid = j;
            }
        }
        if (Wid > -1) {
            v[Wid] = w[i];
        } else {
            v.pb(w[i]);
        }
    }
    printf("%d", v.size());

    /* --------------------------------- */
    printf("\n");
    return 0;
}