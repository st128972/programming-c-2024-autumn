#include <iostream>

int main(int argc, char* argv[]) {
    int n = 0;
    scanf("%d", &n);
    int *a = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    int s = 0;
    for (int i = 0; i < n; ++i) {
        if (*(a + i) > 0) {
            s += *(a + i);
        }
    }
    int mn = 0;
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        if (*(a + i) < *(a + mn)) {
            mn = i;
        }
        else if (*(a + i) > *(a + mx)) {
            mx = i;
        }
    }
    int p = 1;
    for (int i = 0; i < n; ++i) {
        if (mn < i && mx > i) {
            p *= *(a + i);
        }
        else if (mx < i && mn > i) {
            p *= *(a + i);
        }
    }
    printf("%d ", s);
    printf("%d\n", p);
    free(a);
    return 0;
}
