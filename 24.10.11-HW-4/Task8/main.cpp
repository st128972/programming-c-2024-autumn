#include <cstdio>

int main(int argc, char *argv[]) {
    int n = 0;
    scanf("%d", &n);
    int a[1000] = {0};
    int m = 0;
    int k1 = 0;
    int k2 = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    while (m) {
        scanf("%d", &k1);
        scanf("%d", &k2);
        for (int i = k1 - 1; i <= k2 - 1; ++i) {
            printf("%d ", a[i]);
        }
        printf("\n");
        --m;
    }
    return 0;
}
