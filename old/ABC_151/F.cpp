/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2019.12.28 20:13:56
 */

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

double dist(double x0, double y0, double x1, double y1) {
    return sqrt(pow(x1 - x0, 2.0) + pow(y1 - y0, 2.0));
}

signed main() {
    int n;
    double x[60], y[60];
    scanf("%d", &n);
    rep(i, n) scanf("%lf%lf", &x[i], &y[i]);

    if (n == 2) {
        printf("%.10lf\n", dist(x[0], y[0], x[1], y[1]) * 0.5);
        return 0;
    }

    double ret = INF;
    rep(i, n) for (int j = i + 1; j < n; j++) for (int k = j + 1; k < n; k++) {
        double x3, y3, x1, y1, x2, y2;
        double a, b, c, d, X1_2, X2_2, X3_2, ue, st, gyo;
        x1 = x[i];
        y1 = y[i];
        x2 = x[j];
        y2 = y[j];
        x3 = x[k];
        y3 = y[k];
        a = x1 - x2;
        b = y1 - y2;
        c = x2 - x3;
        d = y2 - y3;
        X1_2 = x1 * x1 + y1 * y1;
        X2_2 = x2 * x2 + y2 * y2;
        X3_2 = x3 * x3 + y3 * y3;
        ue = X1_2 - X2_2;
        st = X2_2 - X3_2;
        gyo = a * d - b * c;
        double lb = 0.0000001;
        if (abs(a) < lb) {
            a = 0;
        }
        if (abs(b) < lb) {
            b = 0;
        }
        if (abs(c) < lb) {
            c = 0;
        }
        if (abs(d) < lb) {
            d = 0;
        }
        if (gyo < lb) {
            x3 = x[i];
            y3 = y[i];
            x1 = x[j];
            y1 = y[j];
            x2 = x[k];
            y2 = y[k];
            a = x1 - x2;
            b = y1 - y2;
            c = x2 - x3;
            d = y2 - y3;
            X1_2 = x1 * x1 + y1 * y1;
            X2_2 = x2 * x2 + y2 * y2;
            X3_2 = x3 * x3 + y3 * y3;
            ue = X1_2 - X2_2;
            st = X2_2 - X3_2;
            gyo = a * d - b * c;
            if (gyo < lb) {
                x2 = x[i];
                y2 = y[i];
                x3 = x[j];
                y3 = y[j];
                x1 = x[k];
                y1 = y[k];
                a = x1 - x2;
                b = y1 - y2;
                c = x2 - x3;
                d = y2 - y3;
                X1_2 = x1 * x1 + y1 * y1;
                X2_2 = x2 * x2 + y2 * y2;
                X3_2 = x3 * x3 + y3 * y3;
                ue = X1_2 - X2_2;
                st = X2_2 - X3_2;
                gyo = a * d - b * c;
            }
        }

        double x0, y0, r;
        // disp(gyo);
        if (abs(gyo) < 0.1) {
            double d1 = dist(x[i], y[i], x[j], y[j]);
            double d2 = dist(x[j], y[j], x[k], y[k]);
            double d3 = dist(x[i], y[i], x[k], y[k]);
            if (d1 > d2 && d1 > d3) {
                r = d1 * 0.5;
                x0 = (x[i] + x[j]) * 0.5;
                y0 = (y[i] + y[j]) * 0.5;
            } else if (d2 > d1 && d2 > d3) {
                r = d2 * 0.5;
                x0 = (x[k] + x[j]) * 0.5;
                y0 = (y[k] + y[j]) * 0.5;
            } else {
                r = d3 * 0.5;
                x0 = (x[k] + x[i]) * 0.5;
                y0 = (y[k] + y[i]) * 0.5;
            }
        } else {
            x0 = (d * ue - b * st) / gyo * 0.5;
            y0 = (-c * ue + a * st) / gyo * 0.5;
            if (abs(d * ue - b * st) < lb) {
                x0 = 0;
            }
            if (abs(-c * ue + a * st) < lb) {
                y0 = 0;
            }
            // disp(d * ue - b * st, -c * ue + a * st);
            r = dist(x0, y0, x1, y1);
        }

        bool ok = true;
        rep(l, n) {
            if (l == i || l == j || l == k)
                continue;
            if (dist(x0, y0, x[l], y[l]) + 0.00001 > r) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ret = min(r, ret);
        }
    }

    printf("%.10lf\n", ret);

    /* --------------------------------- */
    return 0;
};
