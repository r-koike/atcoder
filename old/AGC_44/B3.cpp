/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2020.05.23 20:53:47
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

// #define int long long

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

const int M = 100000000;
const int dir_4[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int dir_8[8][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

/* ------------------------------------- */

// ===================### Union-Findの実装 ###=================== //
const int UF_SIZE = 252525;

int par[UF_SIZE]; // 親
int siz[UF_SIZE]; // 木の深さ
int costs[UF_SIZE];

// n要素で初期化
void init(int n) {
    for (int i = 0; i < n; i++) {
        par[i] = i;
        siz[i] = 1;
    }
}
// 木の根を求める
int find(int x) {
    if (par[x] == x) {
        return x;
    } else {
        return par[x] = find(par[x]);
    }
}
// xとyの属する集合を併合
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
        return;

    if (siz[x] < siz[y]) {
        par[x] = y;
        siz[y] += siz[x];
        // if (costs[y] > costs[x]) {
        //     costs[y] = costs[x];
        // }
        costs[y] = min(costs[x], costs[y]);
    } else {
        par[y] = x;
        siz[x] += siz[y];
        costs[x] = min(costs[x], costs[y]);
    }
}
// xとyが同じ集合に属するか否か
bool same(int x, int y) {
    return find(x) == find(y);
}
// xが属する集合の要素数
int size(int x) {
    return siz[find(x)];
}

bool field[550][550];
int p[252525];

signed main() {
    int n;
    scanf("%d", &n);
    int n2 = n * n;
    rep(i, n2) {
        scanf("%d", &p[i]);
        p[i]--;
    }
    init(n2 + 1);

    rep(i, n) rep(j, n) {
        field[i][j] = true;
    }
    rep(hito, n2) {
        int h = hito / n;
        int w = hito % n;
        costs[hito] = min(abs(h), min(abs(w), min(abs(h - n + 1), abs(w - n + 1)))) + 1;
    }
    costs[n2] = 0;

    int ret = 0;
    rep(l, n2) {
        int h = p[l] / n;
        int w = p[l] % n;
        int hito = p[l];
        field[h][w] = false;

        // int co = costs[find(hito)];
        // ret += co;
        int c = INF;
        rep(i, 4) {
            int nh = h + dir_4[i][0];
            int nw = w + dir_4[i][1];
            if (nh < 0 || n <= nh || nw < 0 || n <= nw) {
                c = 0;
                unite(n2, hito);
            } else {
                int nhito = nh * n + nw;
                c = min(c, costs[find(nhito)]);

                // if (!field[h][w] && !field[nh][nw]) {
                // }
                // costs[find(nhito)] >= costs[find(hito)] ||
                if (!field[h][w] && !field[nh][nw]) {
                    unite(hito, nhito);
                }
            }
        }
        rep(i, 4) {
            int nh = h + dir_4[i][0];
            int nw = w + dir_4[i][1];
            if (nh < 0 || n <= nh || nw < 0 || n <= nw) {

            } else {
                int nhito = nh * n + nw;
                if (costs[find(nhito)] > costs[find(hito)] + 1) {
                    costs[find(nhito)] = costs[find(hito)] + 1;
                }
            }
        }
        ret += c;
        // disp(ret, hito, p[hito], find(p[hito]));
        printf("nuketa: (%d, %d)\n", h, w);
        printf("cost: %d\n", c);
        // disp(find(0), find(1), find(2), find(3));
        rep(i, n) {
            rep(j, n) {
                int hito = i * n + j;
                int co = costs[find(hito)];
                printf("%d", co);
            }
            printf("\n");
        }
        printf("++++++++++++++++++++++++++++++++++\n");
    }

    printf("%d\n", ret);

    /* --------------------------------- */
    return 0;
};