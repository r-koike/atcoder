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
#define rep(i, x) for (ll i = 0; i < x; i++)
#define rep1(i, x) for (ll i = 1; i <= x; i++)
#define rrep(i, x) for (ll i = x - 1; i >= 0; i--)
#define rrep1(i, x) for (ll i = x; i > 0; i--)
#define sor(v) sort(v.begin(), v.end())
#define rev(s) reverse(s.begin(), s.end())
#define lb(vec, a) lower_bound(vec.begin(), vec.end(), a)
#define ub(vec, a) upper_bound(vec.begin(), vec.end(), a)
#define uniq(vec) vec.erase(unique(vec.begin(), vec.end()), vec.end())
#define mp1(a, b, c) P1(a, P(b, c))

const int INF = 1000000000;
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

int main() {
    ll A, B;
    ll a_, b_;
    cin >> a_ >> b_;
    A = a_;
    B = b_;
    ll a[43], b[43];
    rep(i, 42) {
        if (a_ % 2 == 0) {
            a[i] = 0;
        } else {
            a[i] = 1;
        }
        a_ = a_ / 2;
        if (b_ % 2 == 0) {
            b[i] = 0;
        } else {
            b[i] = 1;
        }
        b_ = b_ / 2;
    }
    rep(i, 42) cout << a[i];
    cout << endl;
    rep(i, 42) cout << b[i];
    cout << endl;

    ll Am[43], Bm[43], retm[43];
    ll a_i = 50LL;
    ll b_i = 50LL;
    rep(i, 42) {
        if (a_i < i) {
        } else {
            if ((1LL << (i + 1)) > A) {
                a_i = i;
            } else {
                Am[i] = A % (1LL << (i + 1));
            }
        }
        if (b_i < i) {
        } else {
            if ((1LL << (i + 1)) > B) {
                b_i = i;
            } else {
                Bm[i] = B % (1LL << (i + 1));
            }
        }
    }
    rep(i, a_i + 1) { cout << "Am[" << i << "]=" << Am[i] << endl; }
    rep(i, a_i + 1) { cout << "Bm[" << i << "]=" << Bm[i] << endl; }
    cout << "ai" << a_i << "bi" << b_i << endl;
    rep(i, 43) retm[i] = 0;
    rep(i, a_i) {
        if (Am[i] < ((1LL << i) - 1)) {
            retm[i] += 0;
        } else {
            retm[i] += (Am[i] - ((1LL << i) - 1)) % 2;
        }
        cout << "retm[" << i << "]=" << retm[i] << endl;
    }
    rep(i, b_i) {
        if (Bm[i] < ((1LL << i) - 1)) {
            retm[i] += 0;
        } else {
            retm[i] += (Bm[i] - ((1LL << i) - 1)) % 2;
        }
        cout << "retm[" << i << "]=" << retm[i] << endl;
    }

    ll retm1[50], Cm[50];
    rep(i, 43) retm1[i] = 0;
    rep(i, max(b_i, a_i)) {
        Cm[i] = Bm[i] - Am[i];
        if (Cm[i] < ((1LL << i) - 1)) {
            retm1[i] += 0;
        } else {
            retm1[i] += (Cm[i] - ((1LL << i) - 1)) % 2;
        }
        cout << "retm1[" << i << "]=" << retm1[i] << endl;
    }
    rep(i, 43) {
        retm[i] = retm[i] % 2;
        cout << retm[i];
    }

    /* ====================================== */
    cout << endl;
    return 0;
}