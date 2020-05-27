/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2020.05.10 20:51:34
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

const int M = 998244353;
const int dir_4[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int dir_8[8][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

/* ------------------------------------- */

ll n, m, k;
ll f[200020];

// ===================### kが割り切れてもいいmodcomb関係 ###=================== //
// nCk (mod m)をたぶんO(n)で計算する
// k以下の数がmで割り切れても大丈夫
// PRESETするなら，O(n)でPRESETしてO(1)でmodcomb, modcombHを呼べる
// PRESETしないなら，O(n)でmodcomb, modcombHを呼べる
// nは動いてもいい
bool PRESET_KAIJO_ARRAY = true; // 階乗配列をPRESETするか
const ll MAX_KAIJO_N = 200010;  // n%mの最大値?
ll kaijo[MAX_KAIJO_N];
void setKaijo(ll m) {
    kaijo[0] = 1;
    rep1(i, MAX_KAIJO_N - 1) {
        kaijo[i] = (kaijo[i - 1] * i) % m;
    }
}
ll extgcd(ll a, ll b, ll &x, ll &y) {
    ll g = a;
    x = 1;
    y = 0;
    if (b != 0)
        g = extgcd(b, a % b, y, x), y -= (a / b) * x;
    return g;
}
// a^-1を返す
ll modinv(ll a, ll m) {
    ll x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
}
// n!=a*m^eとしたときのa(mod m)を求める
// PRESETされていないならO(n)かかる
ll modfact(ll n, ll m, ll &e) {
    e = 0;
    if (n == 0)
        return 1LL;
    ll ret = modfact(n / m, m, e);
    e += n / m;
    if (!PRESET_KAIJO_ARRAY) {
        kaijo[0] = 1;
        rep1(i, MAX_KAIJO_N - 1) {
            kaijo[i] = (kaijo[i - 1] * i) % m;
        }
    }
    if (n / m % 2 != 0)
        return ret * (m - kaijo[n % m]) % m;
    return ret * kaijo[n % m] % m;
}
// n種類のものからk個を選ぶ場合の数
// PRESETされていないならO(n)かかる
ll modcomb(ll n, ll k, ll m) {
    if (n < 0 || k < 0 || n < k)
        return 0;
    ll e1, e2, e3;
    ll a1 = modfact(n, m, e1), a2 = modfact(k, m, e2), a3 = modfact(n - k, m, e3);
    if (e1 > e2 + e3)
        return 0;
    return a1 * modinv(a2 * a3 % m, m) % m;
}
// n種類のものから重複を許してk個を選ぶ場合の数
// これを使うならnが動くので配列をPRESETしてはいけない
ll modcombH(ll n, ll k, ll m) {
    return modcomb(n + k - 1, n - 1, m);
}

signed main() {
    scanf("%lld%lld%lld", &n, &m, &k);
    setKaijo(M);

    f[0] = m;
    rep1(i, 200002) {
        f[i] = f[i - 1] * (m - 1);
        f[i] %= M;
    }

    ll ret = 0;
    rep(i, k + 1) {
        ret += f[n - i - 1] * modcomb(n - 1, i, M);
        ret %= M;
        // disp(ret);
    }

    printf("%lld\n", ret);

    /* --------------------------------- */
    return 0;
};