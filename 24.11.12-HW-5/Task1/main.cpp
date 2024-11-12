#include<iostream>

int main(int argc, char *argv[]) {
    int n = 0;
    scanf("%d", &n);
    int *a = (int *) malloc(n * sizeof(int));
    int m = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        if (*(a + i) < *(a + m)) {
            m = i;
        }
    }
    for (int i = m; i < n; ++i) {
        printf("%d ", *(a + i));
    }
    for (int i = 0; i < m; ++i) {
        printf("%d ", *(a + i));
    }
    printf("\n");
    free(a);
    return 0;
}
