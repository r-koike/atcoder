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

int main() {
    int a, b, c, d, e, k;
    cin >> a >> b >> c >> d >> e >> k;
    int m;
    m = 0;
    if (m < abs(a - b)) {
        m = abs(a - b);
    }
    if (m < abs(a - c)) {
        m = abs(a - c);
    }
    if (m < abs(a - d)) {
        m = abs(a - d);
    }
    if (m < abs(a - e)) {
        m = abs(a - e);
    }
    if (m < abs(b - c)) {
        m = abs(b - c);
    }
    if (m < abs(b - d)) {
        m = abs(b - d);
    }
    if (m < abs(b - e)) {
        m = abs(b - e);
    }
    if (m < abs(c - d)) {
        m = abs(c - d);
    }
    if (m < abs(c - e)) {
        m = abs(c - e);
    }
    if (m < abs(d - e)) {
        m = abs(d - e);
    }
    if (m > k) {
        printf(":(");
    } else {
        printf("Yay!");
    }

    /* --------------------------------- */
    printf("\n");
    return 0;
}