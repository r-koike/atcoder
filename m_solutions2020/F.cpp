/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2020.07.25 20:39:33
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

const int M = 100000000;
const int dir_4[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int dir_8[8][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

/* ------------------------------------- */

ll n, x[200020], y[200020];
char c[200020];
vp ul, ur, ru, rd, dl, dr, lu, ld;
signed main() {
    scanf("%lld", &n);
    rep(i, n) {
        scanf("%lld%lld", &x[i], &y[i]);
        scanf(" %c", &c[i]);

        if (c[i] == 'U') {
            ul.pb(mp(y[i] + x[i], x[i]));
            ur.pb(mp(x[i] - y[i], -x[i]));
        } else if (c[i] == 'R') {
            ru.pb(mp(y[i] - x[i], -y[i]));
            rd.pb(mp(y[i] + x[i], y[i]));
        } else if (c[i] == 'D') {
            dl.pb(mp(x[i] - y[i], x[i]));
            dr.pb(mp(y[i] + x[i], x[i]));
        } else if (c[i] == 'L') {
            lu.pb(mp(y[i] + x[i], -y[i]));
            ld.pb(mp(y[i] - x[i], y[i]));
        }
    }

    // 第一要素が小さい順，第二要素が小さい順
    sort(ul.begin(), ul.end(), [](const P a, const P b) {
        if (a.fr != b.fr)
            return a.fr < b.fr;
        else
            return a.sc < b.sc;
    });
    sort(ur.begin(), ur.end(), [](const P a, const P b) {
        if (a.fr != b.fr)
            return a.fr < b.fr;
        else
            return a.sc < b.sc;
    });
    sort(ru.begin(), ru.end(), [](const P a, const P b) {
        if (a.fr != b.fr)
            return a.fr < b.fr;
        else
            return a.sc < b.sc;
    });
    sort(rd.begin(), rd.end(), [](const P a, const P b) {
        if (a.fr != b.fr)
            return a.fr < b.fr;
        else
            return a.sc < b.sc;
    });
    sort(dl.begin(), dl.end(), [](const P a, const P b) {
        if (a.fr != b.fr)
            return a.fr < b.fr;
        else
            return a.sc < b.sc;
    });
    sort(dr.begin(), dr.end(), [](const P a, const P b) {
        if (a.fr != b.fr)
            return a.fr < b.fr;
        else
            return a.sc < b.sc;
    });
    sort(lu.begin(), lu.end(), [](const P a, const P b) {
        if (a.fr != b.fr)
            return a.fr < b.fr;
        else
            return a.sc < b.sc;
    });
    sort(ld.begin(), ld.end(), [](const P a, const P b) {
        if (a.fr != b.fr)
            return a.fr < b.fr;
        else
            return a.sc < b.sc;
    });

    ll retmin = INF;
    rep(i, n) {
        if (c[i] == 'U') {
            // rdとld
            ll t1 = y[i] - x[i];
            auto iter1 = lb(ld, P(t1, -INF));
            auto iter2 = ub(ld, P(t1, INF));
            ll num1 = iter2 - iter1;
            if (num1 > 0) {
                P p = *iter1;
            }

            ll t2 = y[i] + x[i];
            auto iter3 = lb(rd, P(t2, -INF));
            auto iter4 = ub(rd, P(t2, INF));
            ll num2 = iter4 - iter3;
        } else if (c[i] == 'R') {
            ru.pb(mp(y[i] - x[i], -y[i]));
            rd.pb(mp(y[i] + x[i], y[i]));
        } else if (c[i] == 'D') {
            dl.pb(mp(x[i] - y[i], x[i]));
            dr.pb(mp(y[i] + x[i], x[i]));
        } else if (c[i] == 'L') {
            lu.pb(mp(y[i] + x[i], -y[i]));
            ld.pb(mp(y[i] - x[i], y[i]));
        }
    }

    /* --------------------------------- */
    return 0;
};