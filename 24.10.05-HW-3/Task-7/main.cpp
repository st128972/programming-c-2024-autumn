#include <cstdio>

int main(int argc, char *argv[]) {
    int n = 0;
    int m = 0;
    scanf("%d", &n);
    scanf("%d", &m);
    int e = 0;
    int c = 0;
    e = n;
    c = m;
    while (e != 0 && c != 0) {
        if (e > c) {
            e = e % c;
        }
        else {
            c = c % e;
        }
    }
    m = e + c;
    printf("%d", n / m);
    return 0;
}