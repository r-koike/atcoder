#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
using ll = long long int;
// using mint = modint1000000007;
const ll INF = 1LL << 60;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(V) V.begin(), V.end()

int main() {
    int H, W, N;
    cin >> H >> W >> N;
    vector<int> tate_old(H, -1), yoko_old(W, -1), tate_new(H, -1), yoko_new(W, -1);
    vector<tuple<int, int, int, int>> V(N);
    vector<int> ANS(N);
    REP(i, N) {
        int r, c, a;
        cin >> r >> c >> a;
        r--;
        c--;
        V[i] = {a, r, c, i};
    }
    sort(ALL(V));
    reverse(ALL(V));
    int w = 0;
    vector<int> tate_ch = {}, yoko_ch = {};
    for (int i = 0; i < N; i++) {
        int a = get<0>(V[i]);
        if (w != a) {
            for (auto x : tate_ch) {
                tate_old[x] = tate_new[x];
            }
            for (auto x : yoko_ch) {
                yoko_old[x] = yoko_new[x];
            }
            w = a;
            tate_ch = {};
            yoko_ch = {};
        }
        int r = get<1>(V[i]);
        int c = get<2>(V[i]);
        int num = get<3>(V[i]);
        int ans = max(tate_old[r], yoko_old[c]) + 1;
        tate_ch.push_back(r);
        yoko_ch.push_back(c);
        tate_new[r] = ans;
        yoko_new[c] = ans;
        ANS[num] = ans;
    }
    for (int i = 0; i < N; i++) {
        cout << ANS[i] << endl;
    }
}