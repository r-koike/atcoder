/**
 * @brief : c++ code for AtCoder
 * @author: rk222
 * @created: 2019.05.04 20:58:01
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
int h, w;
int n;
char ss[200010], tt[200010];
int takaleft, takaright;
int sr, sc;

bool isyoko(char c) {
    return c == 'R' || c == 'L';
}
bool istate(char c) {
    return c == 'U' || c == 'D';
}

int main() {
    scanf("%d%d%d", &h, &w, &n);
    scanf("%d%d", &sr, &sc);
    scanf("%s", &ss);
    scanf("%s", &tt);
    sc--;
    sr--;

    // 横方向について
    bool takaturn = false;
    bool aokiturn = true;
    takaleft = -1;
    takaright = w;
    int mai, mii;
    int cntl = 0, cntr = 0;
    bool ftry = true;
    rrep(i, n) {
        char s = ss[i], t = tt[i];
        if (isyoko(t) && takaturn) {
            // takaの行動処理
            mii = i + 1;
            for (int k = mii; k <= mai; k++) {
                if (ss[k] == 'R') {
                    cntr++;
                } else if (ss[k] == 'L') {
                    cntl++;
                }
            }
            takaright -= cntr;
            takaleft += cntl;
            if (takaright <= takaleft + 1) {
                printf("NO\n");
                return 0;
            }
            cntr = 0;
            cntl = 0;

            // aokiの監視開始
            mai = i;
            aokiturn = true;
            takaturn = false;
        }
        // printf("i:%d left:%d right:%d\n", i, takaleft, takaright);

        if (isyoko(s) && aokiturn) {
            if (!ftry) {
                // aokiの行動処理
                mii = i;
                for (int k = mii; k <= mai; k++) {
                    if (tt[k] == 'R') {
                        cntr++;
                    } else if (tt[k] == 'L') {
                        cntl++;
                    }
                }
                takaleft -= cntr;
                takaright += cntl;
                takaleft = max(-1, takaleft);
                takaright = min(w, takaright);
                cntr = 0;
                cntl = 0;
            }
            ftry = false;

            // takaの監視開始
            mai = i;
            aokiturn = false;
            takaturn = true;
        }
        // printf("i:%d left:%d right:%d\n", i, takaleft, takaright);

        if (i == 0) {
            if (takaturn) {
                mii = i;
                for (int k = mii; k <= mai; k++) {
                    if (ss[k] == 'R') {
                        cntr++;
                    } else if (ss[k] == 'L') {
                        cntl++;
                    }
                }
                takaright -= cntr;
                takaleft += cntl;
                if (takaright <= takaleft + 1) {
                    printf("NO\n");
                    return 0;
                }
            } else if (aokiturn) {
                // aokiの行動処理
                mii = i;
                for (int k = mii; k <= mai; k++) {
                    if (tt[k] == 'R') {
                        cntr++;
                    } else if (tt[k] == 'L') {
                        cntl++;
                    }
                }
                takaleft -= cntr;
                takaright += cntl;
                takaleft = max(-1, takaleft);
                takaright = min(w, takaright);
            }
        }
        // printf("i:%d left:%d right:%d\n", i, takaleft, takaright);
    }

    if (!(takaleft < sc && sc < takaright)) {
        printf("NO\n");
        return 0;
    }

    /* ------------------------------------- */

    // 縦方向についてleftは↑、rightは↓
    takaturn = false;
    aokiturn = true;
    takaleft = -1;
    takaright = h;
    cntl = 0, cntr = 0;
    ftry = true;
    rrep(i, n) {
        char s = ss[i], t = tt[i];
        if (istate(t) && takaturn) {
            // takaの行動処理
            mii = i + 1;
            for (int k = mii; k <= mai; k++) {
                if (ss[k] == 'D') {
                    cntr++;
                } else if (ss[k] == 'U') {
                    cntl++;
                }
            }
            takaright -= cntr;
            takaleft += cntl;
            if (takaright <= takaleft + 1) {
                printf("NO\n");
                return 0;
            }
            cntr = 0;
            cntl = 0;

            // aokiの監視開始
            mai = i;
            aokiturn = true;
            takaturn = false;
        }
        // printf("i:%d left:%d right:%d\n", i, takaleft, takaright);

        if (istate(s) && aokiturn) {
            if (!ftry) {
                // aokiの行動処理
                mii = i;
                for (int k = mii; k <= mai; k++) {
                    if (tt[k] == 'D') {
                        cntr++;
                    } else if (tt[k] == 'U') {
                        cntl++;
                    }
                }
                takaleft -= cntr;
                takaright += cntl;
                takaleft = max(-1, takaleft);
                takaright = min(h, takaright);
                cntr = 0;
                cntl = 0;
            }
            ftry = false;

            // takaの監視開始
            mai = i;
            aokiturn = false;
            takaturn = true;
        }
        // printf("i:%d left:%d right:%d\n", i, takaleft, takaright);

        if (i == 0) {
            if (takaturn) {
                mii = i;
                for (int k = mii; k <= mai; k++) {
                    if (ss[k] == 'D') {
                        cntr++;
                    } else if (ss[k] == 'U') {
                        cntl++;
                    }
                }
                takaright -= cntr;
                takaleft += cntl;
                if (takaright <= takaleft + 1) {
                    printf("NO\n");
                    return 0;
                }
            } else if (aokiturn) {
                // aokiの行動処理
                mii = i;
                for (int k = mii; k <= mai; k++) {
                    if (tt[k] == 'D') {
                        cntr++;
                    } else if (tt[k] == 'U') {
                        cntl++;
                    }
                }
                takaleft -= cntr;
                takaright += cntl;
                takaleft = max(-1, takaleft);
                takaright = min(h, takaright);
            }
        }
        // printf("i:%d left:%d right:%d\n", i, takaleft, takaright);
    }

    if (!(takaleft < sr && sr < takaright)) {
        printf("NO\n");
        return 0;
    }

    printf("YES\n");

    /* --------------------------------- */
    return 0;
}