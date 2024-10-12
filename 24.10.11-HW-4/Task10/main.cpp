#include <cstdio>

int main(int argc, char *argv[]) {
    int n = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    scanf("%d", &n);
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);
    int k[1000] = {0};
    int m = 0;
    for (int i = 0; i < n; ++i) {
        k[i] = i + 1;
    }
    for (int i = 0; i < (b - a + 1) / 2; ++i) {
        m = k[a - 1 + i];
        k[a - 1 + i] = k[b - 1 - i];
        k[b - 1 - i] = m;
    }
    for (int i = 0; i < (d - c + 1) / 2; ++i) {
        m = k[c - 1 + i];
        k[c - 1 + i] = k[d - 1 - i];
        k[d - 1 - i] = m;
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", k[i]);
    }
    return 0;
}
