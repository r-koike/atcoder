#include <math.h>
#include <stdio.h>

#define A_MAX 999
#define N_MAX 100

float cut_over_three(float y) {
    if (y < 1000)
        return y;
    return cut_over_three(y / 10);
}

float factotial_over_three(float x, unsigned int M) {
    if (M < 2)
        return 1;
    return cut_over_three(M *
                          factotial_over_three(M * x, M - 1)); //なんでこれでうまくいくんだ？
}

int main() {
    //入力
    double a, b, c;
    // scanf("%lf%lf%lf",&a,&b,&c);

    long double D = b * b - 4 * a * c;
    if (D <= 0) {
        printf("a,b,c is error");
        return 0;
    }

    //入力を返す
    // printf("\n---input--- \n");
    // printf("a:%.8e \nb:%.8e \n c:%.8e\n\n\n",a,b,c);

    double x_1, x_2; // x1<x_2
    if (b > 0)
        x_1 = (-b - sqrt(D)) / 2 / a;
    if (b < 0)
        x_1 = (-b + sqrt(D)) / 2 / a;
    x_2 = c / a / x_1;

    //出力
    printf("\n---output--- \n");
    printf("x_1:%.8e \nx_2:%.8e \n\n\n", x_1, x_2);
    return 0;
}