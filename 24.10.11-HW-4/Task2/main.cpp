#include <cstdio>

int main(int argc, char *argv[]) {
    int n = 0;
    scanf("%d", &n);
    int l = 0;
    int r = 0;
    int a[1000] = {0};
    int k = -1001;
    int m = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &l);
    scanf("%d", &r);
    for (int i = l - 1; i < r; ++i) {
        if (a[i] > k) {
            k = a[i];
            m = i + 1;
        }
    }
    printf("%d ", k);
    printf("%d\n", m);
    return 0;
}
