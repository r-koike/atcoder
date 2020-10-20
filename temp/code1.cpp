#include <cstdio>

void sensor(float *v) {
    for (int i = 0; i < 8; i++) {
        v[i] = (float)i / 10;
        // v[i] = mcp3208.read_input(i);
    }
}

void sensor_calc(float &a1, float &a2, float &a3, float &a4) {
    float value[8];
    sensor(value);
    a1 = value[0] - value[1]; // A-B
    a2 = value[2] - value[3]; // C-D
    a3 = value[5] - value[4]; // E-F
    a4 = value[7] - value[6]; // G-H
}

int main() {
    float a1, a2, a3, a4;
    sensor_calc(a1, a2, a3, a4);
    printf("%.8f %.8f %.8f %.8f\n", a1, a2, a3, a4);
    return 0;
}