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

vector<P> hakos;

int main() {
    int n;
    cin >> n;
    hakos.resize(n);
    rep(i, n) {
        cin >> hakos[i].fr >> hakos[i].sc;
    }
    sort(hakos.begin(), hakos.end(), [](const P a, const P b) {
        if (a.fr != b.fr)
            return a.fr < b.fr;
        else
            return a.sc > a.sc;
    });
    int ret = 0;
    rep(i, n) {
        int w = hakos[i].sc;
        int dpi = bit_max(w - 1) + 1;
        bit_set(w, dpi);
        ret = max(ret, dpi);
    }
    cout << ret;

    /* --------------------------------- */
    cout << "\n";
    return 0;
}