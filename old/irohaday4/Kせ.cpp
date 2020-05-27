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
const ll M = 1000000007;
const int dir_4[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int dir_8[8][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

/* ------------------------------------- */
ll kaijo[200010];

// mod関係
ll extgcd(ll a, ll b, ll &x, ll &y) {
    ll g = a;
    x = 1;
    y = 0;
    if (b != 0)
        g = extgcd(b, a % b, y, x), y -= (a / b) * x;
    return g;
}
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
ll n, p[200010];
vector<ll> input;

ll dfs(vector<ll> vec) {
    ll len = vec.size();
    if (len <= 2)
        return 1LL;

    auto ite = max_element(vec.begin() + 1, vec.end());
    ll mv = *ite;
    ll mvi = ite - vec.begin();

    vector<ll> vec0 = vector<ll>(vec.begin(), ite);
    vector<ll> vec1 = vector<ll>(ite, vec.end());

    ll ret = ((dfs(vec0) * dfs(vec1)) % M) * modcomb(len - 1LL, len - mvi - 1LL, M);
    return ret % M;
}

int main() {
    kaijo[0] = 1LL;
    rep1(i, 200001) {
        kaijo[i] = (kaijo[i - 1] * i) % M;
    }

    scanf("%lld", &n);
    rep(i, n) scanf("%lld", &p[i]);
    if (p[0] != n) {
        printf("%d\n", 0);
        return 0;
    }

    rep(i, n) input.pb(p[i]);
    printf("%lld\n", dfs(input));

    /* --------------------------------- */
    return 0;
}