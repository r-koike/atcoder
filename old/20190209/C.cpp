#include <iostream>
#include <stdint.h>
#include <string>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    /* ====================================== */
    int K, A, B;
    cin >> K >> A >> B;

    if (B - A < 3) {
        cout << (1 + K);
    } else {
        if (K < A) {
            cout << (1 + K);
        } else {
            int n = K - A + 1;
            int mult = n / 2;
            int ad = n % 2;
            uint64_t res = (uint64_t)A + ((uint64_t)(B - A)) * mult + ad;

            cout << res;
        }
    }

    /* ====================================== */
    return 0;
}