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
typedef pair<ll, ll> P;
typedef pair<ll, P> P1;

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
const ll M = 1000000007;
const int dir_4[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int dir_8[8][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

ll kaijo[200010];

ll extgcd(ll a, ll b, ll &x, ll &y) {
    ll g = a;
    x = 1;
    y = 0;
    if (b != 0)
        g = extgcd(b, a % b, y, x), y -= (a / b) * x;
    return g;
}

// mod. m での a の逆元 a^{-1} を計算する
ll modinv(ll a, ll m) {
    ll x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
}

ll modfact(ll n, ll p, ll &e) {
    e = 0;
    if (n == 0)
        return 1LL;
    ll ret = modfact(n / p, p, e);
    e += n / p;
    if (n / p % 2 != 0)
        return ret * (p - kaijo[n % p]) % p;
    return ret * kaijo[n % p] % p;
}

ll modcomb(ll n, ll k, ll p) {
    if (n < 0 || k < 0 || n < k)
        return 0;
    ll e1, e2, e3;
    ll a1 = modfact(n, p, e1), a2 = modfact(k, p, e2), a3 = modfact(n - k, p, e3);
    if (e1 > e2 + e3)
        return 0;
    return a1 * modinv(a2 * a3 % p, p) % p;
}

/* ------------------------------------- */
ll n, m;
ll dpb[100010], dpa[100010], dpaa[100010];

int main() {
    kaijo[0] = 1LL;
    rep1(i, 200005) {
        kaijo[i] = (kaijo[i - 1] * i) % M;
    }

    scanf("%lld%lld", &n, &m);
    if (n < 3LL) {
        printf("%d\n", 0);
        return 0;
    } else if (n == 3LL) {
        printf("%d\n", 1);
        return 0;
    }

    ll len = n + m;

    ll ret = 0;
    rep(i, len - 3) {
        if (i == 0) {
        }
    }

    /* --------------------------------- */
    return 0;
}