#include <iostream>

int main(int argc, char *argv[]) {
    int n = 0;
    scanf("%d", &n);
    int m = 0;
    scanf("%d", &m);
    int *a = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    int *b = (int *) malloc(m * sizeof(int));
    for (int i = 0; i < m; ++i) {
        scanf("%d", b + i);
    }
    return 0;
}
