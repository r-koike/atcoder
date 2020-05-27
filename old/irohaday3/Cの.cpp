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

const int INF = 100000000;
const int M = 100000000;
const int dir_4[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int dir_8[8][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

/* ------------------------------------- */
ll ad = 10000000000LL;

int main() {
    ll n, k;
    scanf("%lld%lld", &n, &k);

    ll sum = (k - n * 2LL + 2LL) * (k + 1LL) / 2LL;
    rep1(i, n - 1) {
        if (i != 1LL) {
            printf(" ");
        }
        printf("%lld %lld", i, sum - i + ad);
        // v.pb(pair<ll,ll>(i, i));
        // v.pb(pair<ll,ll>(i, sum - i));
    }
    ll num = k - n * 2LL + 2LL;
    rep(i, num) {
        if (i == 0) {
            printf(" %lld", n + i + ad);
        } else {
            printf(" %lld", n + i);
        }
        // v.pb(pair<ll,ll>(n, n + i));
    }

    printf("\n");
    printf("YES\n");

    rep1(i, n - 1) {
        if (i != 1LL) {
            printf(" ");
        }
        printf("%lld %lld", i, i);
        // v.pb(pair<ll,ll>(i, i));
        // v.pb(pair<ll,ll>(i, sum - i));
    }
    rep(i, num) {
        printf(" %lld", n);
        // v.pb(pair<ll,ll>(n, n + i));
    }
    printf("\n");

    /* --------------------------------- */
    return 0;
}