#include <iostream>

int main(int argc, char *argv[]) {
    int n = 0;
    scanf("%d", &n);
    int *a = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    int k = 0;
    scanf("%d", &k);
    k = k % n;
    if (k < 0) {
        k += n;
    }
    int *b = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        *(b + (i + k) % n) = *(a + i);
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", *(b + i));
    }
    printf("\n");
    free(a);
    free(b);
    return 0;
}
