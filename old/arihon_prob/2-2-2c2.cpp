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

const int INF = 10000000;
const int M = 10000000;
const int dir_4[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int dir_8[8][2] = {{1, 0},  {1, 1},   {0, 1},  {-1, 1},
                         {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

// binary indexed tree
int bit[125252];
const int BIT_SIZE = 100025;
// set bit[x] = max(bit[x], v)
void bit_set(int x, int v) {
    for (; x <= BIT_SIZE; x += x & -x) {
        bit[x] = max(bit[x], v);
    }
}
// get max(bit[i]) for i = 1,2,...,x-1,x
int bit_max(int x) {
    int ret = 0;
    for (; x >= 1; x -= x & -x) {
        ret = max(ret, bit[x]);
    }
    return ret;
}

/* ------------------------------------- */

vector<P> hakos;

int main() {
    int n;
    scanf("%d", &n);
    hakos.resize(n);
    rep(i, n) {
        scanf("%d%d", &hakos[i].fr, &hakos[i].sc);
    }
    sort(hakos.begin(), hakos.end(), [](const P a, const P b) {
        if (a.fr != b.fr)
            return a.fr < b.fr;
        else
            return a.sc > b.sc;
    });
    int ret = 0;
    rep(i, n) {
        int w = hakos[i].sc;
        int dpi = bit_max(w - 1) + 1;
        bit_set(w, dpi);
        ret = max(ret, dpi);
    }
    cout << ret;
    cout << "\n";
    return 0;
}
