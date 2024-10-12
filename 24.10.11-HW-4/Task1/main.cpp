#include <iostream>

int main(int argc, char *argv[]) {
    int n = 0;
    scanf("%d", &n);
    int x = 0;
    int a[1000] = {0};
    int k = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &x);
    for (int i = 0; i < n; ++i) {
        if (a[i] == x) {
            k = k + 1;
        }
    }
    printf("%d\n", k);
    return 0;
}
