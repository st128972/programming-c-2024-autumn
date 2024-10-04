#include <cstdio>

int main(int argc, char *argv[]) {
    int a = 0;
    scanf("%d", &a);
    int k = -1;
    int n = 0;
    for (int i = 1; i <= a; ++i) {
        int v = 0;
        int s = 0;
        scanf("%d", &v);
        scanf("%d", &s);
        if (s == 1 && v > n) {
            n = v;
            k = i;
        }
    }
    printf("%d\n", k);
    return 0;
}
