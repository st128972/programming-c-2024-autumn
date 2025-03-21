#include <cstdio>

int main(int argc, char *argv[]) {
    int i = 0;
    int j = 0;
    scanf("%d", &i);
    scanf("%d", &j);
    int f0 = 0;
    int f1 = 1;
    int c = 0;
    int k = 0;
    int n = 0;
    while (i != 0 && j != 0)
        if (i > j) {
            i = i % j;
        }
        else {
            j = j % i;
        }
    n = i + j;
    while (k < n) {
        f0 = f1;
        f1 = c;
        c = (f0 + f1) % 1000000000;
        k = k + 1;
    }
    printf("%d", c);
    return 0;
}
