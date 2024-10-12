#include <cstdio>

int main(int argc, char *argv[]) {
    int n = 0;
    scanf("%d", &n);
    int a[1000] = {0};
    scanf("%d", &a[0]);
    int k = a[0];
    int m = a[0];
    for (int i = 1; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; ++i) {
        if (a[i] > k) {
            k = a[i];
        }
        else if (a[i] < m) {
            m = a[i];
        }
    }
    for (int i = 0; i < n; ++i) {
        if (k == a[i]) {
            a[i] = m;
        }
        printf("%d ", a[i]);
    }
    return 0;
}
