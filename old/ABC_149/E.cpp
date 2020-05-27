/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2019.12.29 19:57:44
 */

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

const ll INF = 100000000;
const ll M = 100000000;
const int dir_4[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int dir_8[8][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

/* ------------------------------------- */

int main() {
    ll n, m;
    scanf("%lld%lld", &n, &m);
    vector<ll> a;
    rep(i, n) {
        ll at;
        scanf("%lld", &at);
        a.pb(at);
    }
    sor(a);

    // 二分探索
    ll MIN_ASUM = 0;
    ll MAX_ASUM = 200000;
    ll kohuku = 100000;
    int su = 0;
    int just = 0;
    ll iii = 0;
    while (1) {
        su = 0;
        just = 0;
        rep(i, n) {
            // if (kohuku - a[i] <= 0) {
            //     su += n;
            //     continue;
            // }
            auto iter1 = lb(a, kohuku - a[i]);
            auto iter2 = ub(a, kohuku - a[i]);
            su += a.end() - iter1;
            just += iter2 - iter1;
        }
        // cout << "kohuku: " << kohuku << endl;
        // cout << "m: " << m << endl;
        // cout << "su: " << su << endl;
        if ((su - just < m && m <= su) || (just == 0 && m == su)) {
            break;
        } else if (su < m) {
            MAX_ASUM = kohuku;
            kohuku -= (kohuku - MIN_ASUM) / 2;
        } else if (m < su) {
            MIN_ASUM = kohuku;
            kohuku += (MAX_ASUM - kohuku) / 2;
        }

        // iii++;
        // if (iii > 100)
        //     break;
    }
    // cout << "kohuku: " << kohuku << endl;
    // cout << "m: " << m << endl;
    // cout << "su: " << su << endl;

    ll asum[100010];
    asum[n] = 0;
    rrep(i, n) {
        asum[i] = asum[i + 1] + a[i];
    }

    ll ret = 0;
    rep(i, n) {
        // if (kohuku - a[i] <= 0) {
        //     cout << "aaaa" << endl;
        //     ret += a[0];
        //     ret += a[i] * n;
        //     continue;
        // }
        auto iter1 = lb(a, kohuku - a[i]);
        ret += asum[iter1 - a.begin()];
        ret += (a.end() - iter1) * a[i];
    }
    ret -= (su - m) * kohuku;

    printf("%lld\n", ret);

    /* --------------------------------- */
    return 0;
}