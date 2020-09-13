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
// x^n (mod m)を返す
// O(log n)
ll modpow(ll x, ll n, ll m) {
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return modpow(x * x % m, n / 2, m);
    else
        return x * modpow(x, n - 1, m) % m;
}

// ===================### mod関係 ###=================== //
// n%pのサイズの階乗配列を準備するか
bool USE_KAIJO_ARRAY = true;
const ll MAX_KAIJO_N = 400010;
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
ll modcomb(ll n, ll k, ll p) {
    if (n < 0 || k < 0 || n < k)
        return 0;
    ll e1, e2, e3;
    ll a1 = modfact(n, p, e1), a2 = modfact(k, p, e2), a3 = modfact(n - k, p, e3);
    if (e1 > e2 + e3)
        return 0;
    return a1 * modinv(a2 * a3 % p, p) % p;
}
ll ans[101] = {};

ll kaijoAns(ll n) {
    if (n >= M) {
        return 0;
    }
    ll k = n / 10000000;
    ll a = ans[k];
    for (ll i = ll(k * 10000000 + 1); i < ll(n + 1); ++i) {
        (a *= i) %= M;
    }
    return a % M;
}

signed main() {
    ans[0] = 1;
    ans[1] = 682498929;
    ans[2] = 491101308;
    ans[3] = 76479948;
    ans[4] = 723816384;
    ans[5] = 67347853;
    ans[6] = 27368307;
    ans[7] = 625544428;
    ans[8] = 199888908;
    ans[9] = 888050723;
    ans[10] = 927880474;
    ans[11] = 281863274;
    ans[12] = 661224977;
    ans[13] = 623534362;
    ans[14] = 970055531;
    ans[15] = 261384175;
    ans[16] = 195888993;
    ans[17] = 66404266;
    ans[18] = 547665832;
    ans[19] = 109838563;
    ans[20] = 933245637;
    ans[21] = 724691727;
    ans[22] = 368925948;
    ans[23] = 268838846;
    ans[24] = 136026497;
    ans[25] = 112390913;
    ans[26] = 135498044;
    ans[27] = 217544623;
    ans[28] = 419363534;
    ans[29] = 500780548;
    ans[30] = 668123525;
    ans[31] = 128487469;
    ans[32] = 30977140;
    ans[33] = 522049725;
    ans[34] = 309058615;
    ans[35] = 386027524;
    ans[36] = 189239124;
    ans[37] = 148528617;
    ans[38] = 940567523;
    ans[39] = 917084264;
    ans[40] = 429277690;
    ans[41] = 996164327;
    ans[42] = 358655417;
    ans[43] = 568392357;
    ans[44] = 780072518;
    ans[45] = 462639908;
    ans[46] = 275105629;
    ans[47] = 909210595;
    ans[48] = 99199382;
    ans[49] = 703397904;
    ans[50] = 733333339;
    ans[51] = 97830135;
    ans[52] = 608823837;
    ans[53] = 256141983;
    ans[54] = 141827977;
    ans[55] = 696628828;
    ans[56] = 637939935;
    ans[57] = 811575797;
    ans[58] = 848924691;
    ans[59] = 131772368;
    ans[60] = 724464507;
    ans[61] = 272814771;
    ans[62] = 326159309;
    ans[63] = 456152084;
    ans[64] = 903466878;
    ans[65] = 92255682;
    ans[66] = 769795511;
    ans[67] = 373745190;
    ans[68] = 606241871;
    ans[69] = 825871994;
    ans[70] = 957939114;
    ans[71] = 435887178;
    ans[72] = 852304035;
    ans[73] = 663307737;
    ans[74] = 375297772;
    ans[75] = 217598709;
    ans[76] = 624148346;
    ans[77] = 671734977;
    ans[78] = 624500515;
    ans[79] = 748510389;
    ans[80] = 203191898;
    ans[81] = 423951674;
    ans[82] = 629786193;
    ans[83] = 672850561;
    ans[84] = 814362881;
    ans[85] = 823845496;
    ans[86] = 116667533;
    ans[87] = 256473217;
    ans[88] = 627655552;
    ans[89] = 245795606;
    ans[90] = 586445753;
    ans[91] = 172114298;
    ans[92] = 193781724;
    ans[93] = 778983779;
    ans[94] = 83868974;
    ans[95] = 315103615;
    ans[96] = 965785236;
    ans[97] = 492741665;
    ans[98] = 377329025;
    ans[99] = 847549272;
    ans[100] = 698611116;
    kaijo[0] = 1LL;
    rep1(i, MAX_KAIJO_N) {
        kaijo[i] = (kaijo[i - 1] * i) % M;
    }
    ll n, a, b;
    scanf("%lld%lld%lld", &n, &a, &b);

    ll ret = myPow(2, n, M);
    ll nCa = ((kaijoAns(n) * modinv(kaijoAns(n - a), M)) % M * modinv(kaijoAns(a), M)) % M;
    ll nCb = ((kaijoAns(n) * modinv(kaijoAns(n - b), M)) % M * modinv(kaijoAns(b), M)) % M;
    // disp(myPow(2, n, M));
    // disp(nCa, nCb);
    ret = (((ret - nCa - nCb - 1) % M) + M) % M;

    printf("%lld\n", ret);

    /* --------------------------------- */
    return 0;
};