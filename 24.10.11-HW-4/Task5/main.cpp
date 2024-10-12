#include <cstdio>
#include <cmath>

int main(int argc, char *argv[]) {
    int n = 0;
    scanf("%d", &n);
    int a[1000] = {0};
    int x = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &x);
    int k = a[0];
    for (int i = 0; i < n; ++i) {
        if (abs(a[i] - x) == abs(k - x) && a[i] < k || abs(a[i] - x) < abs(k - x)) {
            k = a[i];
        }
    }
    printf("%d\n", k);
    return 0;
}
