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
const int dir_8[8][2] = {{1, 0},  {1, 1},   {0, 1},  {-1, 1},
                         {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

/* ------------------------------------- */

int n, q;
char s[100010];
char t[100010], d[100010];

int sn;
bool cald[100010]; // t[i]が計算済みかに対応
map<string, P> mpp;

int main() {
    scanf("%d%d", &n, &q);
    scanf("%s", s);
    rep(i, q) {
        scanf(" %c", &t[i]);
        scanf(" %c", &d[i]);
    }

    sn = 0;
    rep(i, q) {
        if (!cald[i]) {
            int cur = 0;
            int cLmin = 0, cRmax = 0;
            rep(j, q) {
                if (t[j] == t[i]) {
                    if (d[j] == 'L')
                        cur--;
                    else
                        cur++;
                    cLmin = min(cLmin, cur);
                    cRmax = max(cRmax, cur);
                    cald[j] = true;
                }
            }

            mpp[string(1, t[i])] = mp(cLmin, cRmax);
            sn++;
        }
    }
    int ret = 0;
    rep(i, n) {
        int cL = mpp[string(1, s[i])].fr;
        int cR = mpp[string(1, s[i])].sc;
        if (i >= -cL && n - i - 1 >= cR) {
            ret++;
        } else {
        }
    }
    cout << endl;
    cout << mpp["A"].fr << "," << mpp["A"].sc << endl;
    cout << mpp["B"].fr << "," << mpp["B"].sc << endl;

    printf("%d", ret);

    /* --------------------------------- */
    printf("\n");
    return 0;
}