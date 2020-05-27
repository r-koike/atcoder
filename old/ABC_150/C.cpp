/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2019.12.28 20:13:56
 */

// #define int long long

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

int n, p[11], q[11];
int car[10];
int a, b;

void check(int jisyo) {
    bool bl = false;
    rep(i, n) {
        if (car[i] != p[i]) {
            break;
        }
        if (i == n - 1) {
            bl = true;
        }
    }
    if (bl) {
        a = jisyo;
    }
    bl = false;
    rep(i, n) {
        if (car[i] != q[i]) {
            break;
        }
        if (i == n - 1) {
            bl = true;
        }
    }
    if (bl) {
        b = jisyo;
    }
    // disp(a, b);
}

signed main() {
    scanf("%d", &n);
    rep(i, n) {
        scanf("%d", &p[i]);
    }
    rep(i, n) {
        scanf("%d", &q[i]);
    }

    int kaiso;
    int jisyo = 0;
    rep1(i, n) {
        kaiso = 0;
        car[kaiso] = i;
        rep1(j, n) {
            kaiso = 1;
            car[kaiso] = j;
            if (i == j)
                continue;
            if (kaiso + 1 >= n) {
                jisyo++;
                check(jisyo);
                continue;
            }
            rep1(k, n) {
                kaiso = 2;
                car[kaiso] = k;
                if (i == k || j == k)
                    continue;
                if (kaiso + 1 >= n) {
                    // disp(kaiso, n, jisyo);
                    jisyo++;
                    check(jisyo);
                    continue;
                }
                rep1(l, n) {
                    kaiso = 3;
                    car[kaiso] = l;
                    if (i == l || j == l || k == l)
                        continue;
                    if (kaiso + 1 >= n) {
                        jisyo++;
                        check(jisyo);
                        continue;
                    }
                    rep1(i1, n) {
                        kaiso = 4;
                        car[kaiso] = i1;
                        if (i == i1 || j == i1 || k == i1 || l == i1)
                            continue;
                        if (kaiso + 1 >= n) {
                            jisyo++;
                            check(jisyo);
                            continue;
                        }
                        rep1(j1, n) {
                            kaiso = 5;
                            car[kaiso] = j1;
                            if (i == j1 || j == j1 || k == j1 || l == j1 || i1 == j1)
                                continue;
                            if (kaiso + 1 >= n) {
                                jisyo++;
                                check(jisyo);
                                continue;
                            }
                            rep1(k1, n) {
                                kaiso = 6;
                                car[kaiso] = k1;
                                if (i == k1 || j == k1 || k == k1 || l == k1 || i1 == k1 ||
                                    j1 == k1)
                                    continue;
                                if (kaiso + 1 >= n) {
                                    jisyo++;
                                    check(jisyo);
                                    continue;
                                }
                                rep1(l1, n) {
                                    kaiso = 7;
                                    car[kaiso] = l1;
                                    if (i == l1 || j == l1 || k == l1 || l == l1 || i1 == l1 ||
                                        j1 == l1 || k1 == l1)
                                        continue;
                                    if (kaiso + 1 >= n) {
                                        jisyo++;
                                        check(jisyo);
                                        continue;
                                    }
                                    jisyo++;
                                    check(jisyo);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    printf("%d\n", abs(a - b));

    /* --------------------------------- */
    return 0;
};