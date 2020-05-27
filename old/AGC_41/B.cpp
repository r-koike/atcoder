/**
 * @brief  : c++ code for AtCoder
 * @author : rk222
 * @created: 2019.12.28 20:11:47
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

string s3set1[2] = {"abb", "eff"};
string s3set2[2] = {"a.c", "e.g"};
string s3set3[2] = {"ddc", "hhg"};

string s4set1[2] = {"ijkk", "qrss"};
string s4set2[2] = {"ijll", "qrtt"};
string s4set3[2] = {"mmop", "uuwy"};
string s4set4[2] = {"nnop", "vvwy"};

string s5set1[2] = {"aac..", "iik.."};
string s5set2[2] = {"bbc..", "jjk.."};
string s5set3[2] = {"...de", "...lm"};
string s5set4[2] = {"...de", "...lm"};
string s5set5[2] = {"...ff", "...nn"};

int main() {
    int n;
    scanf("%d", &n);

    if (n == 2) {
        printf("%d\n", -1);
        return 0;
    } else if (n == 3) {
        string s1, s2, s3;
        s1 = "abb";
        s2 = "a.c";
        s3 = "ddc";
        printf("%s\n", s1.c_str());
        printf("%s\n", s2.c_str());
        printf("%s\n", s3.c_str());
    } else if (n == 4) {
        string s1, s2, s3, s4;
        s1 = "abcc";
        s2 = "abdd";
        s3 = "eegh";
        s4 = "ffgh";
        printf("%s\n", s1.c_str());
        printf("%s\n", s2.c_str());
        printf("%s\n", s3.c_str());
        printf("%s\n", s4.c_str());
    } else {
        if (n % 3 == 0) {
            vector<string> ret;
            rep(i, n / 3) {
                string stemp = "";
                ret.pb(stemp);
                ret.pb(stemp);
                ret.pb(stemp);
                rep(j, n / 3) {
                    string s1, s2, s3;
                    s1 = s3set1[(i + j) % 2];
                    s2 = s3set2[(i + j) % 2];
                    s3 = s3set3[(i + j) % 2];
                    ret[3 * i] = ret[3 * i] + s1;
                    ret[3 * i + 1] = ret[3 * i + 1] + s2;
                    ret[3 * i + 2] = ret[3 * i + 2] + s3;
                    // printf("i:%d j:%d\n", i, j);
                    // printf("%s\n", ret[i].c_str());
                    // printf("%s\n", ret[i + 1].c_str());
                    // printf("%s\n", ret[i + 2].c_str());
                }
            }
            rep(i, n) printf("%s\n", ret[i].c_str());
        } else if (n % 4 == 0) {
            vector<string> ret;
            int n4 = n / 4;
            rep(i, n4) {
                string stemp = "";
                ret.pb(stemp);
                ret.pb(stemp);
                ret.pb(stemp);
                ret.pb(stemp);
                rep(j, n4) {
                    string s1, s2, s3, s4;
                    s1 = s4set1[(i + j) % 2];
                    s2 = s4set2[(i + j) % 2];
                    s3 = s4set3[(i + j) % 2];
                    s4 = s4set4[(i + j) % 2];
                    ret[4 * i] = ret[4 * i] + s1;
                    ret[4 * i + 1] = ret[4 * i + 1] + s2;
                    ret[4 * i + 2] = ret[4 * i + 2] + s3;
                    ret[4 * i + 3] = ret[4 * i + 3] + s4;
                }
            }
            rep(i, n) printf("%s\n", ret[i].c_str());
        } else if (n % 5 == 0) {
            vector<string> ret;
            int n5 = n / 5;
            rep(i, n5) {
                string stemp = "";
                ret.pb(stemp);
                ret.pb(stemp);
                ret.pb(stemp);
                ret.pb(stemp);
                ret.pb(stemp);
                rep(j, n5) {
                    string s1, s2, s3, s4, s5;
                    s1 = s5set1[(i + j) % 2];
                    s2 = s5set2[(i + j) % 2];
                    s3 = s5set3[(i + j) % 2];
                    s4 = s5set4[(i + j) % 2];
                    s5 = s5set5[(i + j) % 2];
                    ret[5 * i] = ret[5 * i] + s1;
                    ret[5 * i + 1] = ret[5 * i + 1] + s2;
                    ret[5 * i + 2] = ret[5 * i + 2] + s3;
                    ret[5 * i + 3] = ret[5 * i + 3] + s4;
                    ret[5 * i + 4] = ret[5 * i + 4] + s5;
                }
            }
            rep(i, n) printf("%s\n", ret[i].c_str());
        } else {
            printf("%d\n", -1);
        }
    }

    /* --------------------------------- */
    return 0;
}