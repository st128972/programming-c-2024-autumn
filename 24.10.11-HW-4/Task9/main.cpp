#include <cstdio>

int main(int argc, char *argv[]) {
    int n = 0;
    scanf("%d", &n);
    int a[1000] = {0};
    int x = 0;
    int k = 1;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &x);
    for (int i = 0; i < n; ++i) {
        if (a[i] >= x) {
            k++;
        }
        else {
            break;
        }
    }
    printf("%d\n", k);
    return 0;
}
