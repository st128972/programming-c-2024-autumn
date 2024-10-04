#include <cstdio>

int main(int argc, char *argv[]) {
    int a = 0;
    int b = 0;
    scanf("%d", &a);
    scanf("%d", &b);
    int c = 0;
    int k = 0;
    int n = 0;
    k = a;
    n = b;
    while (k != 0 && n != 0) {
        if (k > n) {
            k = k % n;
        }
        else {
            n = n % k;
        }
    }
    printf("%d\n", (a * b) / (n + k));
    return 0;
}
