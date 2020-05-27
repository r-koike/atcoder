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
const ll M = 1000000000 + 7;
const int dir_4[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int dir_8[8][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

/* ------------------------------------- */
ll q, ns[100100], ks[100100];
ll kaijo[100010];

// vector<vector<ll>> comb(ll n, ll r) {
//     vector<vector<ll>> v(n + 1, vector<ll>(n + 1, 0));
//     for (int i = 0; i < v.size(); i++) {
//         v[i][0] = 1;
//         v[i][i] = 1;
//     }
//     for (int j = 1; j < v.size(); j++) {
//         for (int k = 1; k < j; k++) {
//             v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
//         }
//     }
//     return v;
// }

// mod. m での a の逆元 a^{-1} を計算する
ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0)
        u += m;
    return u;
}

ll comb(ll n, ll r) {
    return ((kaijo[n] * modinv(kaijo[n - r], M)) % M * modinv(kaijo[r], M)) % M;
}

bool issquare(ll n) {
    ll tmp = (ll)sqrt(n);
    return tmp * tmp == n;
}

int main() {
    kaijo[0] = 1LL;
    rep1(i, 100000) {
        kaijo[i] = (kaijo[i - 1] * i) % M;
    }

    scanf("%lld", &q);
    rep(i, q) scanf("%lld%lld", &ns[i], &ks[i]);

    rep(i, q) {
        ll n = ns[i];
        ll k = ks[i];

        if (n % 2 == 0LL) {
            ll s = n / 2;
            if (issquare(s * s - 2 * k)) {
                ll t = s - (ll)sqrt(s * s - 2 * k);
                if (0 <= t && t <= s) {
                    ll ret = (2LL * comb(s, t)) % M;
                    printf("%lld\n", ret);
                } else {
                    printf("%d\n", 0);
                }
            } else {
                printf("%d\n", 0);
            }
        } else {
            ll s = (n - 1) / 2;
            if (issquare((2 * s + 1) * (2 * s + 1) - 2 * k * 4)) {
                ll t = (2 * s + 1) - (ll)sqrt((2 * s + 1) * (2 * s + 1) / 4 - 2 * k);
                if (0 <= t && t <= s) {
                    ll ret = (2LL * comb(s, t)) % M;
                    printf("%lld\n", ret);
                } else {
                    printf("%d\n", 0);
                }
            } else {
                printf("%d\n", 0);
            }
        }
    }

    /* --------------------------------- */
    return 0;
}