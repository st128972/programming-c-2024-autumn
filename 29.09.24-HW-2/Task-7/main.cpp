#include <cstdio>

int main(int argc, char *argv[]) {
    int k = 0;
    int m = 0;
    int n = 0;
    scanf("%d", &k);
    scanf("%d", &m);
    scanf("%d", &n);
    int a = 0;
    if (n <= k) {
        a = 2;
    }
    else if (n == 0) {
        a = 0;
    }
    else {
        a = (2 * n + k - 1) / k;
    }
    printf("%d\n", a * m);

    return 0;
}
