#include <cstdio>

int main(int argc, char* argv[]) {
    int n = 0;
    scanf("%d", &n);
    int a = 0;
    int b = 0;
    if (n % 5 == 0) {
        b = n / 5;
        a = 0;
        printf("%d", b);
        printf(" ");
        printf("%d", a);
    }
    else if (n % 5 == 1 || n % 5 == 4) {
        b = n / 5 - 1;
        a = (n - (b * 5)) / 3;
        printf("%d", b);
        printf(" ");
        printf("%d", a);
    }
    else if (n % 5 == 2) {
        b = n / 5 - 2;
        a= (n - (b * 5)) / 3;
        printf("%d", b);
        printf(" ");
        printf("%d", a);
    }
    else if (n % 5 == 3) {
        b = n / 5;
        a = 1;
        printf("%d", b);
        printf(" ");
        printf("%d", a);
    }
    return 0;
}
