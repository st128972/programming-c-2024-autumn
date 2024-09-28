#include <cstdio>

int main(int argc, char* argv[]) {
    int n = 0;
    int m = 0;
    scanf("%d", &n);
    scanf("%d", &m);
    int a = 0;
    if (n > m) {
        n = n + m;
        m = n - m;
        n = n - m;
    }
    if (n == 1) {
        a = 4 * m;
    }
    else if (n % 2 == 0 && m % 2 == 0) {
        a = 2 * ((n + 1) * m + n);
    }
    else {
        a = (m + 1) * n + (n + 1) * m;
        a = a + ((2 * (m - 1) + 2 * (n - 1)) / 2);
        if (n * m % 2 == 0) {
            a = a + 2;
        }
    }
    printf("%d", a);
    return 0;
}