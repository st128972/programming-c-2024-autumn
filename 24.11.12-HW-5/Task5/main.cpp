#include <iostream>

int main(int argc, char *argv[]) {
    int n = 0;
    scanf("%d", &n);
    int *a = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    int mx = 0;
    int s = 0;
    for (int i = n - 1; i >= 0; --i) {
        mx = std::max(mx, *(a + i));
        s += mx;
    }
    printf("%d\n", s);
    free(a);
    return 0;
}
