#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    /* ====================================== */
    int a[3], b[3];
    cin >> a[0] >> b[0] >> a[1] >> b[1] >> a[2] >> b[2];
    string n = "NO";
    string y = "YES";
    int count0, count1, count2, count3;
    count0 = 0;
    count1 = 0;
    count2 = 0;
    count3 = 0;

    for (int i = 0; i < 3; i++) {
        if (a[i] == 1) {
            count0++;
        } else if (a[i] == 2) {
            count1++;
        } else if (a[i] == 3) {
            count2++;
        } else if (a[i] == 4) {
            count3++;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (b[i] == 1) {
            count0++;
        } else if (b[i] == 2) {
            count1++;
        } else if (b[i] == 3) {
            count2++;
        } else if (b[i] == 4) {
            count3++;
        }
    }
    switch (count0) {
    case 0:
        int j = 0;
        break;
    case 1:
        int i = 0;
        break;
    }

    if (count0 > 2 || count1 > 2 || count2 > 2 || count3 > 2) {
        cout << n;
    } else {
        cout << y;
    }

    /* ====================================== */
    return 0;
}