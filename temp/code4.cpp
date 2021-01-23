#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
    printf("std::abs -> %lf\n", std::abs(-2.4));
    printf("abs -> %lf\n", abs(-2.4));
    double x = abs(-2.4);
    printf("x -> %lf\n", x);
}
