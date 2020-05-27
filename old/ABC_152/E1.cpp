/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2019.12.28 20:13:56
 */

#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <bitset>
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

#define int long long

typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef pair<int, P> P1;
typedef tuple<int, int, int> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<tuple<int, int, int>> vt;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define rep(i, x) for (int i = 0; i < x; i++)
#define rep1(i, x) for (int i = 1; i <= x; i++)
#define srep(i, s, x) for (int i = s; i < x; i++)
#define rrep(i, x) for (int i = x - 1; i >= 0; i--)
#define rrep1(i, x) for (int i = x; i > 0; i--)
#define rsrep(i, s, x) for (int i = x - 1; i >= s; i--)
#define maxs(x, y) (x = max(x, y))
#define mins(x, y) (x = min(x, y))
#define limit(x, l, r) max(l, min(x, r))
#define lims(x, l, r) (x = max(l, min(x, r)))
#define sor(v) sort(v.begin(), v.end())
#define rev(s) reverse(s.begin(), s.end())
#define lb(vec, a) lower_bound(vec.begin(), vec.end(), a)
#define ub(vec, a) upper_bound(vec.begin(), vec.end(), a)
#define uniq(vec) vec.erase(unique(vec.begin(), vec.end()), vec.end())
#define mp1(a, b, c) P1(a, P(b, c))
#define dame                                                                                  \
    puts("-1");                                                                               \
    return 0
#define yn                                                                                    \
    puts("Yes");                                                                              \
    else puts("No")
#define YN                                                                                    \
    puts("YES");                                                                              \
    else puts("NO")

template <typename A, typename B> string to_string(pair<A, B> p);
template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
string to_string(const string &s) {
    return '"' + s + '"';
}
string to_string(const char *s) {
    return to_string((string)s);
}
string to_string(bool b) {
    return (b ? "true" : "false");
}
string to_string(vector<bool> v) {
    bool first = true;
    string ret = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            ret += ", ";
        }
        first = false;
        ret += to_string(v[i]);
    }
    ret += "}";
    return ret;
}
template <size_t N> string to_string(bitset<N> v) {
    string ret = "";
    for (size_t i = 0; i < N; i++) {
        ret += static_cast<char>('0' + v[i]);
    }
    return ret;
}
template <typename A> string to_string(A v) {
    bool first = true;
    string ret = "{";
    for (const auto &x : v) {
        string s = to_string(x);
        if (!first) {
            ret += ", ";
        }
        if (s[0] == '{') {
            s = "\n" + s;
        }
        first = false;
        ret += s;
    }
    if (ret[ret.size() - 1] == '}') {
        ret += "\n}";
    } else {
        ret += "}";
    }
    return ret;
}
template <typename A, typename... Lest> string to_string(A *v, int n, Lest... L) {
    bool first = true;
    string ret = "{";
    rep(i, n) {
        auto x = v[i];
        string s = to_string(x, L...);
        if (!first) {
            ret += ", ";
        }
        if (s[0] == '{') {
            s = "\n" + s;
        }
        first = false;
        ret += s;
    }
    if (ret[ret.size() - 1] == '}') {
        ret += "\n}";
    } else {
        ret += "}";
    }
    return ret;
}
template <typename A, typename B> string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
           to_string(get<2>(p)) + ")";
}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
           to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
void name_disp(string s) {
    cerr << "-------" << endl;
    cerr << s << ": " << endl;
}
void val_disp() {
    cerr << endl;
}
template <typename First, typename... Lest> void val_disp(First F, Lest... L) {
    cerr << to_string(F) << endl;
    val_disp(L...);
}
template <typename A, typename... Lest> void val_disp(A *v, Lest... L) {
    cerr << to_string(v, L...) << endl;
    val_disp();
}
#define disp(...)                                                                             \
    name_disp(#__VA_ARGS__);                                                                  \
    val_disp(__VA_ARGS__)
#define adisp(a, ...)                                                                         \
    name_disp(#a);                                                                            \
    val_disp(a, __VA_ARGS__)

#ifdef int
const ll INF = 1002003004005006007ll;
#else
const int INF = 1002003004;
#endif

const int M = 1000000007;
const int dir_4[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int dir_8[8][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

/* ------------------------------------- */

// ===================### 素数取得 ###=================== //
bool primeDp[1000000];
vector<int> getPrimes(int n) {
    int u = n + 32;
    double lu = log(u);
    vector<int> ret((int)(u / lu + u / lu / lu * 1.5));

    for (int i = 2; i <= n; i++)
        primeDp[i] = true;
    int sqn = sqrt(n);
    for (int i = 2; i <= sqn; i++) {
        if (!primeDp[i])
            continue;
        for (int j = i * i; j <= n; j += i)
            primeDp[j] = false;
    }
    int idx = 0;
    for (int i = 2; i <= n; i++) {
        if (primeDp[i]) {
            ret[idx] = i;
            idx++;
        }
    }
    return vector<int>(ret.begin(), ret.begin() + idx);
}

// ===================### mod関係 ###=================== //

// ===================### mod関係 ###=================== //
// n%pのサイズの階乗配列を準備するか
bool USE_KAIJO_ARRAY = true;
const ll MAX_KAIJO_N = 1000000;
ll kaijo[MAX_KAIJO_N];
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
    ll kai;
    if (USE_KAIJO_ARRAY) {
        kai = kaijo[n % p];
    } else {
        kai = 1;
        rep1(i, n % p) {
            kai = (kai * i) % p;
        }
    }
    if (n / p % 2 != 0)
        return ret * (p - kai) % p;
    return ret * kai % p;
}

ll dp[10000];
ll dp1[10000];

signed main() {
    kaijo[0] = 1LL;
    rep1(i, MAX_KAIJO_N) {
        kaijo[i] = (kaijo[i - 1] * i) % M;
    }
    ll n, a[10010];
    scanf("%lld", &n);
    rep(i, n) scanf("%lld", &a[i]);

    vi primes = getPrimes(1000000);

    ll N = 0;
    rep(i, n) {
        ll b = a[i];
        ll N1 = 0;
        rep(j, primes.size()) {
            if (b == 1) {
                break;
            }
            ll p = primes[j];
            ll num = 0;
            while (1) {
                if (b % p == 0) {
                    b /= p;
                    num++;
                } else {
                    break;
                }
            }
            dp[j] = max(dp[j], num);
            N1++;
        }
        N = max(N, N1);
    }
    // rep(i, 31) {
    //     printf("%lld\n", dp[i]);
    // }
    // printf("%lld\n", N);

    ll ret = 0;
    rep(i, n) {
        ll b = a[i];
        ll N3 = 0;
        rep(j, primes.size()) {
            if (N3 == N + 1) {
                break;
            }
            ll p = primes[j];
            ll num = 0;
            while (1) {
                if (b % p == 0) {
                    b /= p;
                    num++;
                } else {
                    break;
                }
            }
            dp1[j] = dp[j] - num;
            N3++;
        }
        // rep(j, 31) {
        //     printf("%lld, %lld\n", i, dp1[j]);
        // }
        ll ret1 = 1;
        rep(j, N) {
            ll p = primes[j];
            ll po = 1;
            po = modfact(p, dp[i], M);
            ret1 *= po;
            ret1 %= M;
        }
        ret += ret1;
        ret %= M;
    }

    printf("%lld\n", ret % M);

    /* --------------------------------- */
    return 0;
};