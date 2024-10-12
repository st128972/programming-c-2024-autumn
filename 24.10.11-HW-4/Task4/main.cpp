#include <cstdio>

int main(int argc, char *argv[]) {
    int n = 0;
    scanf("%d", &n);
    int a[1000] = {0};
    int mx = 0;
    int k = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            k = a[0] + a[1] + a[n - 1];
        }
        else if (i == n - 1) {
            k = a[n - 1] + a[0] + a[n - 2];
        }
        else {
            k = a[i - 1] + a[i] + a[i + 1];
        }
        if (k > mx) {
            mx = k;
        }
    }
    printf("%d\n", mx);
    return 0;
}
