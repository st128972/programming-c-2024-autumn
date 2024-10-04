#include <cstdio>

int main(int argc, char *argv[]) {
    int a = 0;
    int n = 0;
    int m = 0;
    scanf("%d", &a);
    for (int i = 1; i <= a; ++i) {
        scanf("%d", &n);
        scanf("%d", &m);
        printf("%d\n", 19 * m + (n + 239) * (n + 366) / 2);
    }
    return 0;
}
