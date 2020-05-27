/*----------------------------------------------/
/- char         : %c  | char *       : %s  | short        : %hd
/- int          : %d  | long         : %ld | long long    : %lld
/- unsigned short:%hu | unsigned int : %u  | unsigned long: %lu
/- u_long long  : %llu| (octal)      : %o  | (hexadecimal): %x
/- float        : %f  | double       : %lf |
/----------------------------------------------*/

/*----------------------------------------------/
/- INT_MAX, LONG_MAX   : 1<<31 = 2.1*pow(10, 9)       (= 2147483647)
/- UINT_MAX, ULONG_MAX : 1<<32 = 4.2*pow(10, 9)       (= 4294967295)
/- LLONG_MAX           : 1<<63 = 9.2*pow(10, 18)      (= 9223372036854775807)
/- ULLONG_MAX          : 1<<64 = 1.8*pow(10, 19)      (= 18446744073709551615)
/----------------------------------------------*/

// ===================### 時間の目安 ###=================== //
// 2secのとき，
// N = 10^8 → 非常にシンプルな処理なら間に合う
// N = 10^7 → 恐らく間に合う

// 300^3 = 2.7 * 10^7
// 2^26 = 6.7 * 10^7
// 3^16 = 4.3 * 10^7
// 11! = 4.0 * 10^7

// ===================### 配列サイズの目安 ###=================== //
// int d[30000][30000];  ならいける
// int d[900000000ll];  ならいける(9*10^8のサイズ)

// ===================### 時間測定 ###=================== //
// 時間測定
#include <chrono>
auto stime = chrono::system_clock::now(); // 計測開始時刻
// 処理
auto etime = chrono::system_clock::now(); // 計測終了時刻
double elapsed = chrono::duration_cast<chrono::milliseconds>(etime - stime)
                     .count(); //処理に要した時間をミリ秒に変換
cout << "elapsed: " << elapsed << "ms" << endl;

// ===================### char →　int ###=================== //
int ctoi(char c) {
    int ret = c - '0';
    if (0 <= ret && ret < 10) {
        return ret;
    } else {
        return -1;
    }
}

// ===================### 最大公約数 ###=================== //
int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}

// ===================### ソート関係 ###=================== //
// 第一要素が小さい順
sort(vec.begin(), vec.end(), [](const P a, const P b) {
    if (a.fr != b.fr)
        return a.fr < b.fr;
    else
        return a.sc < b.sc;
});

// ===================### ソート関係 ###=================== //
// 第二要素が小さい順
sort(vec.begin(), vec.end(), [](const P a, const P b) {
    if (a.sc != b.sc)
        return a.sc < b.sc;
    else
        return a.fr < b.fr;
});

// ===================### valを左に6桁で0埋めしたstringを作る ###=================== //
#include <iomanip>
ostringstream sout;
sout << setfill('0') << setw(6) << val;
string s = sout.str();

// ===================### BITの実装(1) ###=================== //
// x番目をより大きい値に更新でき、x番目までのうちの最大値を得られる
// 1から始まる
// binary indexed tree
int bit[125252];
const int BIT_SIZE = 100025;
// set bit[x] = max(bit[x], v)
void bit_set(int x, int v) {
    for (; x <= BIT_SIZE; x += x & -x) {
        bit[x] = max(bit[x], v);
    }
}
// get max(bit[i]) for i = 1,2,...,x-1,x
int bit_max(int x) {
    int ret = 0;
    for (; x >= 1; x -= x & -x) {
        ret = max(ret, bit[x]);
    }
    return ret;
}

// ===================### BITの実装(2) ###=================== //
// x番目にvを加えられ、x番目までの和を得られる
// 1から始まる
// binary indexed tree
int bit[125252];
const int BIT_SIZE = 100025;
// add v to bit[x]
void bit_add(int x, int v) {
    for (; x <= BIT_SIZE; x += x & -x) {
        bit[x] += v;
    }
}
// get sum(bit[i]) for i = 1,2,...,x-1,x
int bit_sum(int x) {
    int ret = 0;
    for (; x >= 1; x -= x & -x) {
        ret += bit[x];
    }
    return ret;
}

// ===================### Union-Findの実装 ###=================== //
const int UF_SIZE = 100010;

int par[UF_SIZE]; // 親
int siz[UF_SIZE]; // 木の深さ

// n要素で初期化
void init(int n) {
    for (int i = 0; i < n; i++) {
        par[i] = i;
        siz[i] = 1;
    }
}
// 木の根を求める
int find(int x) {
    if (par[x] == x) {
        return x;
    } else {
        return par[x] = find(par[x]);
    }
}
// xとyの属する集合を併合
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
        return;

    if (siz[x] < siz[y]) {
        par[x] = y;
        siz[y] += siz[x];
    } else {
        par[y] = x;
        siz[x] += siz[y];
    }
}
// xとyが同じ集合に属するか否か
bool same(int x, int y) {
    return find(x) == find(y);
}
// xが属する集合の要素数
int size(int x) {
    return siz[find(x)];
}

// ===================### 階乗、組み合わせ ###=================== //
// 階乗とそれの構成式
const ll MAX_KAIJO_N = 100010;
ll kaijo[MAX_KAIJO_N];
void setKaijo(ll m) {
    kaijo[0] = 1;
    rep1(i, MAX_KAIJO_N - 1) {
        kaijo[i] = (kaijo[i - 1] * i) % m;
    }
}

ll comb(ll n, ll r) {
    return kaijo[n] / kaijo[n - r] / kaijo[r];
}

// ===================### mod関係 ###=================== //
// x^n (mod m)を返す
// O(log n)
ll modpow(ll x, ll n, ll m) {
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return modpow(x * x % m, n / 2, m);
    else
        return x * modpow(x, n - 1, m) % m;
}

// ===================### kが割り切れてもいいmodcomb関係 ###=================== //
// nCk (mod m)をたぶんO(n)で計算する
// k以下の数がmで割り切れても大丈夫
// PRESETするなら，O(n)でPRESETしてO(1)でmodcomb, modcombHを呼べる
// PRESETしないなら，O(n)でmodcomb, modcombHを呼べる
// nは動いてもいい
bool PRESET_KAIJO_ARRAY = true; // 階乗配列をPRESETするか
const ll MAX_KAIJO_N = 100010;  // n%mの最大値?
ll kaijo[MAX_KAIJO_N];
void setKaijo(ll m) {
    kaijo[0] = 1;
    rep1(i, MAX_KAIJO_N - 1) {
        kaijo[i] = (kaijo[i - 1] * i) % m;
    }
}
ll extgcd(ll a, ll b, ll &x, ll &y) {
    ll g = a;
    x = 1;
    y = 0;
    if (b != 0)
        g = extgcd(b, a % b, y, x), y -= (a / b) * x;
    return g;
}
// a^-1を返す
ll modinv(ll a, ll m) {
    ll x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
}
// n!=a*m^eとしたときのa(mod m)を求める
// PRESETされていないならO(n)かかる
ll modfact(ll n, ll m, ll &e) {
    e = 0;
    if (n == 0)
        return 1LL;
    ll ret = modfact(n / m, m, e);
    e += n / m;
    if (!PRESET_KAIJO_ARRAY) {
        kaijo[0] = 1;
        rep1(i, MAX_KAIJO_N - 1) {
            kaijo[i] = (kaijo[i - 1] * i) % m;
        }
    }
    if (n / m % 2 != 0)
        return ret * (m - kaijo[n % m]) % m;
    return ret * kaijo[n % m] % m;
}
// n種類のものからk個を選ぶ場合の数
// PRESETされていないならO(n)かかる
ll modcomb(ll n, ll k, ll m) {
    if (n < 0 || k < 0 || n < k)
        return 0;
    ll e1, e2, e3;
    ll a1 = modfact(n, m, e1), a2 = modfact(k, m, e2), a3 = modfact(n - k, m, e3);
    if (e1 > e2 + e3)
        return 0;
    return a1 * modinv(a2 * a3 % m, m) % m;
}
// n種類のものから重複を許してk個を選ぶ場合の数
// これを使うならnが動くので配列をPRESETしてはいけない
ll modcombH(ll n, ll k, ll m) {
    return modcomb(n + k - 1, n - 1, m);
}

// ===================### O(k)のmodcomb関係 ###=================== //
// nCk (mod m)をたぶんO(k)で計算する
// k以下の数はmで割り切れてはいけない
// nを固定するなら配列をO(k)でPRESETしてO(1)でmodcombを呼べる
// nを動かすなら配列をPRESETしてはいけない，O(k)でmodcomb, O(n)でmodcombHを呼べる
bool PRESET_KAIJO_ARRAY = true; // 階乗配列をPRESETするか
const ll MAX_KAIJO_K = 100010;  // k(%m)の最大値?
ll kaijo[MAX_KAIJO_K];
ll kaijoNtoN_i[MAX_KAIJO_K]; // n*(n-1)*...*(n-i)
void setKaijos(ll n, ll m) {
    kaijo[0] = 1;
    kaijoNtoN_K[0] = n;
    rep1(i, MAX_KAIJO_K - 1) {
        kaijo[i] = (kaijo[i - 1] * i) % m;
        kaijoNtoN_i[i] = (kaijoNtoN_i[i - 1] * i) % m;
    }
}
ll extgcd(ll a, ll b, ll &x, ll &y) {
    ll g = a;
    x = 1;
    y = 0;
    if (b != 0)
        g = extgcd(b, a % b, y, x), y -= (a / b) * x;
    return g;
}
// a^-1を返す
ll modinv(ll a, ll m) {
    ll x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
}
// n種類のものからk個を選ぶ場合の数
// PRESETされていないならO(k)かかる
ll modcomb(ll n, ll k, ll m) {
    if (n < 0 || k < 0 || n < k)
        return 0;
    if (!PRESET_KAIJO_ARRAY) {
        kaijo[0] = 1;
        kaijoNtoN_K[0] = n;
        rep1(i, k) {
            kaijo[i] = (kaijo[i - 1] * i) % m;
            kaijoNtoN_i[i] = (kaijoNtoN_i[i - 1] * i) % m;
        }
    }
    return kaijoNtoN_i[k] * modinv(kaijo[k] % m, m) % m;
}
// n種類のものから重複を許してk個を選ぶ場合の数
// これを使うならnが動くので配列をPRESETしてはいけない
ll modcombH(ll n, ll k, ll m) {
    return modcomb(n + k - 1, n - 1, m);
}

// ===================### 数え上げ関係 ###=================== //
// パスカルの三角形のr行,c列目を返す関数
ll pasc(ll r, ll c) {
    if (c > r) {
        swap(r, c);
    }
    ll n = r + c - 1;
    ll k = c;
    return modcomb(n - 1, k - 1, M);
}

// ===================### modint ###=================== //
// modint: M 計算を int を扱うように扱える構造体
template <int M> struct ModInt {
    ll x;
    constexpr ModInt(ll v = 0) noexcept : x(v % M) {
        if (x < 0)
            x += M;
    }
    constexpr int getmod() {
        return M;
    }
    constexpr ModInt operator-() const noexcept {
        return x ? M - x : 0;
    }
    constexpr ModInt operator+(const ModInt &r) const noexcept {
        return ModInt(*this) += r;
    }
    constexpr ModInt operator-(const ModInt &r) const noexcept {
        return ModInt(*this) -= r;
    }
    constexpr ModInt operator*(const ModInt &r) const noexcept {
        return ModInt(*this) *= r;
    }
    constexpr ModInt operator/(const ModInt &r) const noexcept {
        return ModInt(*this) /= r;
    }
    constexpr ModInt &operator+=(const ModInt &r) noexcept {
        x += r.x;
        if (x >= M)
            x -= M;
        return *this;
    }
    constexpr ModInt &operator-=(const ModInt &r) noexcept {
        x -= r.x;
        if (x < 0)
            x += M;
        return *this;
    }
    constexpr ModInt &operator*=(const ModInt &r) noexcept {
        x = x * r.x % M;
        return *this;
    }
    constexpr ModInt &operator/=(const ModInt &r) noexcept {
        ll a = r.x, b = M, u = 1, v = 0;
        while (b) {
            ll t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        x = x * u % M;
        if (x < 0)
            x += M;
        return *this;
    }
    constexpr bool operator==(const ModInt &r) const noexcept {
        return this->x == r.x;
    }
    constexpr bool operator!=(const ModInt &r) const noexcept {
        return this->x != r.x;
    }
};

using mint = ModInt<M>;

// ===================### 素数取得 ###=================== //
bool primeDp[1000000000];
// だいたいO(n)
vector<int> getPrimes(int n) {
    int u = n + 32;
    double lu = log(u);
    vector<int> ret((int)(u / lu + u / lu / lu * 1.5));

    for (int i = 2; i <= n; i++)
        primeDp[i] = true;
    int sqn = sqrt(n);
    for (int i = 2; i <= sqn; i++) {
        if (!primeDp[i])
            continue;
        for (int j = i * i; j <= n; j += i)
            primeDp[j] = false;
    }
    int idx = 0;
    for (int i = 2; i <= n; i++) {
        if (primeDp[i]) {
            ret[idx] = i;
            idx++;
        }
    }
    return vector<int>(ret.begin(), ret.begin() + idx);
}

// ===================### 最小共通祖先 ###=================== //

vector<int> G[100010];

int parent[100010];
int depth[100010];
int root;
void dfsLca(int v, int p, int d) {
    parent[v] = p;
    depth[v] = d;
    for (int i = 0; i < G[v].size(); i++) {
        if (G[v][i] != p)
            dfsLca(G[v][i], v, d + 1);
    }
}
void init() {
    dfsLca(root, -1, 0);
}
int lca(int u, int v) {
    while (depth[u] > depth[v])
        u = parent[u];
    while (depth[v] > depth[u])
        v = parent[v];
    while (u != v) {
        v = parent[v];
        u = parent[u];
    }
    return u;
}

int main() {
    // lcaの初期処理
    root = 0;
    init();

    int par = lca(3, 4);
}

// ===================### 階乗mod Mを求める ###=================== //
ll kaijoModData[101] = {
    1,         682498929, 491101308, 76479948,  723816384, 67347853,  27368307,  625544428,
    199888908, 888050723, 927880474, 281863274, 661224977, 623534362, 970055531, 261384175,
    195888993, 66404266,  547665832, 109838563, 933245637, 724691727, 368925948, 268838846,
    136026497, 112390913, 135498044, 217544623, 419363534, 500780548, 668123525, 128487469,
    30977140,  522049725, 309058615, 386027524, 189239124, 148528617, 940567523, 917084264,
    429277690, 996164327, 358655417, 568392357, 780072518, 462639908, 275105629, 909210595,
    99199382,  703397904, 733333339, 97830135,  608823837, 256141983, 141827977, 696628828,
    637939935, 811575797, 848924691, 131772368, 724464507, 272814771, 326159309, 456152084,
    903466878, 92255682,  769795511, 373745190, 606241871, 825871994, 957939114, 435887178,
    852304035, 663307737, 375297772, 217598709, 624148346, 671734977, 624500515, 748510389,
    203191898, 423951674, 629786193, 672850561, 814362881, 823845496, 116667533, 256473217,
    627655552, 245795606, 586445753, 172114298, 193781724, 778983779, 83868974,  315103615,
    965785236, 492741665, 377329025, 847549272, 698611116,
};

// 10^7回の計算をする
// 正確にはn (mod 10^7)回の計算をする
ll kaijoModM(ll n) {
    if (n >= M) {
        return 0;
    }
    ll k = n / 10000000;
    ll a = kaijoModData[k];
    for (ll i = k * 10000000 + 1; i < n + 1; i++) {
        (a *= i) %= M;
    }
    return a;
}

// ===================### 順列全探索 ###=================== //
vi order;
rep(i, n) {
    order.pb(i);
}

do {

} while (next_permutation(order.begin(), order.end()));

// ===================### 二分探索 ###=================== //
// vec[i]>keyを満たすiのうち最小のものをubとして返す
ll left = -1, right = n;
while (right - left > 1) {
    ll mid = (left + right) / 2;
    if (vec[mid] > key) { // ここが条件式
        right = mid;
    } else {
        left = mid;
    }
}

// ===================### その他 ###=================== //
// 桁数を求める
int keta = floor(log10(X) + 1);
