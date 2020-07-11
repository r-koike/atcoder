/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2020.07.11 20:53:53
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
    {                                                                                         \
        puts("-1");                                                                           \
        return 0;                                                                             \
    }
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

ll nummod_[200020];
ll nummod[200020];
ll nummodp[200020];
ll dsum_;
ll dsum;
ll dsump;

ll func(ll now) {
    ll temp = 0;
    ll nowt = now;
    while (nowt > 0) {
        temp += nowt % 2;
        nowt /= 2;
    }
    return now % temp;
}

char str_temp[200020];
signed main() {
    int n;
    scanf("%lld", &n);
    scanf("%s", str_temp);
    string s(str_temp);

    ll dCount = 0;
    rep(i, n) {
        if (s[i] == '1') {
            dCount++;
        }
    }

    vi vec;

    ll temp = dCount;
    if (dCount > 0) {
        nummod[0] = 1 % temp;
        rep1(i, n - 1) {
            nummod[i] = (nummod[i - 1] * 2) % temp;
        }
    }
    if (dCount - 1 > 0) {
        temp = dCount - 1;
        nummod_[0] = 1 % temp;
        rep1(i, n - 1) {
            nummod_[i] = (nummod_[i - 1] * 2) % temp;
        }
    }
    temp = dCount + 1;
    nummodp[0] = 1 % temp;
    rep1(i, n - 1) {
        nummodp[i] = (nummodp[i - 1] * 2) % temp;
    }

    dsum_ = 0;
    dsum = 0;
    dsump = 0;
    rep(i, n) {
        if (s[i] == '1') {
            if (dCount - 1 > 0) {
                dsum_ = (dsum_ + nummod_[n - i - 1]) % (dCount - 1);
            }
            if (dCount > 0) {
                dsum = (dsum + nummod[n - i - 1]) % dCount;
            }
            dsump = (dsump + nummodp[n - i - 1]) % (dCount + 1);
        }
    }

    rep(i, n) {
        if (s[i] == '0') {
            ll a = (dsump + nummodp[n - i - 1]) % (dCount + 1);
            vec.pb(a);
        } else {
            ll a = 0;
            if (dCount - 1 > 0) {
                a = (dsum_ - nummod_[n - i - 1]) % (dCount - 1);
                a = (a + (dCount - 1)) % (dCount - 1);
            } else {
                a = -1;
            }
            vec.pb(a);
        }
    }

    // disp(dsum_, dsum, dsump);

    // disp(nummod_, 3);
    // disp(nummod, 3);
    // disp(nummodp, 3);
    // disp(vec);

    rep(i, n) {
        ll now = vec[i];
        ll num;
        if (now == -1) {
            num = -1;
        } else {
            num = 0;
        }
        while (now > 0) {
            now = func(now);
            num++;
        }
        ll ret = num + 1;
        printf("%lld\n", ret);
    }

    /* --------------------------------- */
    return 0;
};