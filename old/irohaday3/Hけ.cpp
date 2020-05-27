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

/* ------------------------------------- */

ll N2(ll n) {
    return 1LL << n;
}

char itoc(ll i) {
    switch (i) {
    case 0:
        return 'a';
    case 1:
        return 'b';
    case 2:
        return 'c';
    case 3:
        return 'd';
    case 4:
        return 'e';
    case 5:
        return 'f';
    case 6:
        return 'g';
    case 7:
        return 'h';
    case 8:
        return 'i';
    case 9:
        return 'j';
    case 10:
        return 'k';
    case 11:
        return 'l';
    case 12:
        return 'm';
    case 13:
        return 'n';
    case 14:
        return 'o';
    case 15:
        return 'p';
    case 16:
        return 'q';
    case 17:
        return 'r';
    case 18:
        return 's';
    case 19:
        return 't';
    case 20:
        return 'u';
    case 21:
        return 'v';
    case 22:
        return 'w';
    case 23:
        return 'x';
    case 24:
        return 'y';
    case 25:
        return 'z';
    }
    return '0';
}

int main() {
    ll q;
    char cs[100010];
    ll es[100010];
    scanf("%lld", &q);
    rep(i, q) {
        scanf(" %c", &cs[i]);
        scanf("%lld", &es[i]);
    }
    rep(i, q) {
        char c = cs[i];
        ll e = es[i];
        if (e == 0LL) {
            if (c != 'a') {
                printf("aa\n");
            } else {
                printf("a\n");
            }
            continue;
        }
        ll n = -1LL, sl = 0LL;
        rrep(j, 62) {
            rrep1(k, 25) {
                if (e == k * (1LL << j)) {
                    n = j;
                    sl = k + n;
                }
                if (n >= 0LL)
                    break;
            }
            if (n >= 0LL)
                break;
        }
        if (n == -1LL) {
            printf("-1\n");
            continue;
        }
        bool b = false;
        rep(j, sl - n + 1) {
            if (itoc(j) != c) {
                if (j == sl - n && !b) {
                    rep(k, n) {
                        printf("%c", c);
                    }
                } else {
                    printf("%c", itoc(j));
                }
            } else {
                rep(k, n) {
                    printf("%c", c);
                }
                b = true;
            }
        }
        printf("\n");
    }

    /* --------------------------------- */
    return 0;
}