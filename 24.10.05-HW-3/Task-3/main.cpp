#include <cstdio>

int main(int argc, char *argv[]) {
    int a = 0;
    scanf("%d", &a);
    int k = 0;
    int n = 0;
    for (int i = 1; i <= a; ++i) {
        int b = 0;
        scanf("%d", &b);
        if (b <= 437) {
            n += 1;
            k = i;
            break;
        }
    }
    if (n > 0) {
        printf("Crash ");
        printf("%d", k);
    }
    else {
        printf("No crash");
    }
    return 0;
}
