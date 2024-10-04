#include <cstdio>

int main(int argc, char *argv[]) {
    int a = 0;
    scanf("%d", &a);
    int k = 0;
    int n = 0;
    for (int i = 0; i < a; ++i) {
        int b = 0;
        scanf("%d", &b);
        if (b == 1) {
            k = k + 1;
        }
        else {
            n = n + 1;
        }
    }
    if (k > n) {
        printf("%d", n);
    }
    else {
        printf("%d", k);
    }
    return 0;
}
