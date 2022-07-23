#include <iostream>

int main() {
    int N;
    uint32_t C;
    std::cin >> N >> C;

    uint32_t t = 0xffffffffull;
    uint32_t f = 0x0000;

    uint32_t X = C;

    for (int i = 0; i < N; ++i) {
        uint32_t T, A;
        std::cin >> T >> A;

        switch (T) {
        case 1:
            t &= A;
            f &= A;
            break;
        case 2:
            t |= A;
            f |= A;
            break;
        case 3:
            t ^= A;
            f ^= A;
            break;
        }

        X = (X & t) | (~X & f);
        std::cout << X << std::endl;
    }

    return 0;
}