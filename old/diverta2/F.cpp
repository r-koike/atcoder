/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2019.06.15 20:56:36
 */

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

// ===================### 最大公約数 ###=================== //
ll gcd(ll a, ll b) {
    if (a % b == 0LL) {
        return (b);
    } else {
        return (gcd(b, a % b));
    }
}
/* ------------------------------------- */

ll x[55], y[55], b[55];
ll n;

int main() {
    scanf("%lld", &n);
    rep(i, n) scanf("%lld%lld", &x[i], &y[i]);

    rep(i, n) b[i] = true;

    ll ret = 0;
    ll cnt = 0;
    while (cnt < n) {
        ret++;
        ll id = -1;
        rep(i, n) {
            if (b[i]) {
                id = i;
                b[i] = false;
                cnt++;
                break;
            }
        }
        if (cnt >= n) {
            break;
        }

        ll x0 = x[id];
        ll y0 = y[id];

        ll maxdnum = -1;
        ll did = -1;
        rep(i, n) {
            if (!b[i]) {
                continue;
            }
            // x[i],y[i]は未使用の数値
            ll x1 = x[i];
            ll y1 = y[i];

            ll p = abs(x1 - x0);
            ll q = abs(y1 - y0);
            if (p < q) {
                swap(p, q);
            }

            bool ze = false;
            if (p == 0) {
                q = 1;
                ze = true;
            } else if (q == 0) {
                p = 1;
                ze = true;
            } else {
                ll pqgcd = gcd(p, q);
                p /= pqgcd;
                q /= pqgcd;
            }
            ll dnum = 0LL;

            if (ze) {
                if (dnum > maxdnum) {
                    maxdnum = dnum;
                    did = i;
                }
                continue;
            }

            rep(j, n) {
                if (!b[j]) {
                    continue;
                }
                bool b1, b2;
                ll c1, c2;
                if ((p == 0 && x0 == x[j]) ||
                    (p != 0 && abs(x0 - x[j]) > 0 && abs(x0 - x[j]) % p == 0)) {
                    b1 = true;
                    if (p == 0) {
                        c1 = 0;
                    } else {
                        c1 = abs(x0 - x[j]) / p;
                    }
                } else {
                    b1 = false;
                }
                if ((q == 0 && y0 == y[j]) ||
                    (q != 0 && abs(y0 - y[j]) > 0 && abs(y0 - y[j]) % q == 0)) {
                    b2 = true;
                    if (q == 0) {
                        c2 = 0;
                    } else {
                        c2 = abs(y0 - y[j]) / q;
                    }
                } else {
                    b2 = false;
                }

                if (b1 && b2) {
                    if (c1 == 0 || c2 == 0 || (c1 > 0 && c2 > 0 && c1 == c2)) {
                        dnum++;
                    }
                }
            }
            if (dnum > maxdnum) {
                maxdnum = dnum;
                did = i;
            }
        }

        // 実際にdidのものを消す
        ll x1 = x[did];
        ll y1 = y[did];
        ll p = abs(x1 - x0);
        ll q = abs(y1 - y0);
        bool ze = false;
        if (p == 0) {
            q = 1;
            ze = true;
        } else if (q == 0) {
            p = 1;
            ze = true;
        } else {
            ll pqgcd = gcd(p, q);
            p /= pqgcd;
            q /= pqgcd;
        }
        if (ze) {
            continue;
        }
        // disp(p);
        // disp(q);
        b[did] = false;
        cnt++;
        rep(j, n) {
            if (!b[j]) {
                continue;
            }
            bool b1, b2;
            ll c1, c2;
            if ((p == 0 && x0 == x[j]) ||
                (p != 0 && abs(x0 - x[j]) > 0 && abs(x0 - x[j]) % p == 0)) {
                b1 = true;
                if (p == 0) {
                    c1 = 0;
                } else {
                    c1 = abs(x0 - x[j]) / p;
                }
            } else {
                b1 = false;
            }
            if ((q == 0 && y0 == y[j]) ||
                (q != 0 && abs(y0 - y[j]) > 0 && abs(y0 - y[j]) % q == 0)) {
                b2 = true;
                if (q == 0) {
                    c2 = 0;
                } else {
                    c2 = abs(y0 - y[j]) / q;
                }
            } else {
                b2 = false;
            }
            if (b1 && b2) {
                if (c1 == 0 || c2 == 0 || (c1 > 0 && c2 > 0 && c1 == c2)) {
                    b[j] = false;
                    cnt++;
                }
            }
        }
    }

    printf("%lld\n", ret);

    /* --------------------------------- */
    return 0;
}