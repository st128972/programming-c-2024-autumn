#include <cstdio>

int main(int argc, char *argv[]) {
    int a = 0;
    scanf("%d", &a);
    int k = 0;
    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= a; ++j) {
            int b = 0;
            scanf("%d", &b);
            k += b;
        }
    }
    printf("%d", k / 2);
    return 0;
}
