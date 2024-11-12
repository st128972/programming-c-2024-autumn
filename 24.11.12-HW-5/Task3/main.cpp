#include <iostream>

int main(int argc, char *argv[]) {
    int n = 0;
    scanf("%d", &n);
    int *a = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    int s1 = 0;
    int s2 = 0;
    for (int i = 0; i < n; ++i) {
        if (*(a + i) % 2 == 0) {
            s1 += 1;
        }
        else {
            s2 += 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (*(a + i) % 2 != 0) {
            printf("%d ", *(a + i));
        }
    }
    printf("\n");
    for (int i = 0; i < n; ++i) {
        if (*(a + i) % 2 == 0) {
            printf("%d ", *(a + i));
        }
    }
    printf("\n");
    if (s1 >= s2) {
        printf("YES");
    }
    else {
        printf("NO");
    }
    free(a);
    return 0;
}
