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
char field[12][12];
int n;

int main() {
    string s;
    scanf("%d", &n);
    rep(i, n) {
        cin >> s;
        rep(j, n) {
            field[i + 1][j + 1] = s[j];
        }
    }
    int judge[2] = {-1, -1};
    int cur[2] = {2, 2};
    char act = '-';
    char prev = 'W';
    int x, y;
    while (1) {
        x = cur[0];
        y = cur[1];
        if (prev != 'W') {
            act = prev;
            prev = 'W';
        } else if (judge[0] == -1 && judge[1] == -1) {
            act = '-';
        } else if (field[x + 1][y] == '.' && field[x + 2][y] == '.' &&
                   !(x < judge[0] && y == judge[1])) {
            act = 'D';
            prev = 'D';
            cur[0] += 2;
        } else if (field[x - 1][y] == '.' && field[x - 2][y] == '.' &&
                   !(x > judge[0] && y == judge[1])) {
            act = 'U';
            prev = 'U';
            cur[0] -= 2;
        } else if (field[x][y + 1] == '.' && field[x][y + 2] == '.' &&
                   !(y < judge[1] && x == judge[0])) {
            act = 'R';
            prev = 'R';
            cur[1] += 2;
        } else if (field[x][y - 1] == '.' && field[x][y - 2] == '.' &&
                   !(y > judge[1] && x == judge[0])) {
            act = 'L';
            prev = 'L';
            cur[1] -= 2;
        }
        printf("%c\n", act);
        cout << flush;

        scanf("%d%d", &judge[0], &judge[1]);
        if (judge[0] == -2 && judge[1] == -2) {
            break;
        }
        if (judge[0] == -3 && judge[1] == -3) {
            break;
        }
    }

    /* --------------------------------- */
    return 0;
}