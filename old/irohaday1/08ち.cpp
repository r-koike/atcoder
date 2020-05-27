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

#define disp(x) cout << #x << ": " << x << endl
#define disp_vec(v)                                                                           \
    cout << #v << ":";                                                                        \
    rep(i, v.size()) cout << " " << v[i];                                                     \
    cout << endl

const ll INF = 100000000;
const ll M = 100000000;
const int dir_4[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int dir_8[8][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

/* ------------------------------------- */

ll solve(ll n, bool b) {
    if (!b) {
        ll keta = n / 9;
        ll r = n % 9;
        ll ret = r;
        rep(i, keta) {
            ret *= 10LL;
            ret += 9LL;
        }
        return ret;
    } else {
        if (n < 10)
            switch (n) {
            case 1:
                return 10;
            case 2:
                return 11;
            case 3:
                return 12;
            case 4:
                return 13;
            case 5:
                return 14;
            case 6:
                return 15;
            case 7:
                return 16;
            case 8:
                return 17;
            case 9:
                return 18;
            }
        ll keta = n / 9;
        ll r = n % 9;
        ll ret = r;
        rep(i, keta) {
            ret *= 10LL;
            ret += 9LL;
        }
        ll ret1 = ret;
        ll cnt = 0;
        while (1) {
            if (ret1 % 10LL != 9LL) {
                ret1++;
                break;
            }
            cnt++;
            ret1 /= 10LL;
        }
        rep(i, cnt) {
            ret1 *= 10LL;
            ret1 += 9LL;
            if (i == 0)
                ret1 -= 1LL;
        }
        return ret1;
    }
}

int main() {
    ll n_, n;
    ll nori;
    scanf("%lld", &n_);
    nori = n_;
    n = 0;
    while (n_) {
        ll tmp = n_ % 10LL;
        n += tmp;
        n_ /= 10;
    }
    ll ret = solve(n, false);

    printf("%lld\n", solve(n, ret == nori));

    /* --------------------------------- */
    return 0;
}