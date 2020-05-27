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
ll ps[40000];
ll rets[4000];

int main() {
    ll n;
    ll k;
    ll pl = 0;
    ll cnt = 0;
    scanf("%lld%lld", &n, &k);
    if (k == 1) {
        printf("%lld\n", n);
        return 0;
    }
    ll loop = (ll)sqrt(n) + 1LL;
    for (ll i = 2LL; i <= loop; i++) {
        bool esc = false;
        rep(j, pl) {
            if (i % ps[j] == 0LL) {
                esc = true;
                break;
            }
        }
        if (esc)
            continue;
        ps[pl] = i;
        pl++;

        // iは素数
        while (n % i == 0LL) {
            rets[cnt] = i;
            cnt++;
            n /= i;
            if (n == 1LL) {
                printf("%d\n", -1);
                return 0;
            }
            if (cnt == k - 1LL) {
                rets[cnt] = n;
                cnt++;
                rep(l, cnt) {
                    if (l == cnt - 1LL) {
                        printf("%lld", rets[l]);
                    } else {
                        printf("%lld ", rets[l]);
                    }
                }
                printf("\n");
                return 0;
            }
        }
    }
    printf("%d\n", -1);
    return 0;

    /* --------------------------------- */
    return 0;
}