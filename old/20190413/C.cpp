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

//#define int long long

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define rep(i, x) for (int i = 0; i < x; i++)
#define rep1(i, x) for (int i = 1; i <= x; i++)
#define rrep(i, x) for (int i = x - 1; i >= 0; i--)
#define rrep1(i, x) for (int i = x; i > 0; i--)
#define sor(v) sort(v.begin(), v.end())
#define rev(s) reverse(s.begin(), s.end())
#define lb(vec, a) lower_bound(vec.begin(), vec.end(), a)
#define ub(vec, a) upper_bound(vec.begin(), vec.end(), a)
#define uniq(vec) vec.erase(unique(vec.begin(), vec.end()), vec.end())
#define mp1(a, b, c) P1(a, P(b, c))

const int INF = 100000000;
const int M = 100000000;
const int dir_4[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int dir_8[8][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

/* ------------------------------------- */

char s[100010], s0[100010], s1[100010];
int main() {
    cin >> s;
    int n;
    rep(i, 100010) {
        if (s[i] == '\0') {
            n = i;
            break;
        }
    }
    rep(i, n) {
        if (i % 2 == 0) {
            s0[i] = '0';
            s1[i] = '1';
        } else {
            s0[i] = '1';
            s1[i] = '0';
        }
    }
    int cnt0 = 0;
    int cnt1 = 0;
    rep(i, n) {
        if (s[i] != s0[i]) {
            cnt0++;
        }
        if (s[i] != s1[i]) {
            cnt1++;
        }
    }
    cout << min(cnt0, cnt1);

    /* --------------------------------- */
    cout << endl;
    return 0;
}