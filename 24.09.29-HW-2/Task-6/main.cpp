#include <cstdio>
#include <cmath>

int main(int argc, char *argv[]) {
    long long a = 0;
    long long b = 0;
    long long c = 0;
    scanf("%lld", &a);
    scanf("%lld", &b);
    scanf("%lld", &c);
    long long d = b * b - 4 * a * c;
    if (a != 0 && (d == 0)) {
        printf("1\n");
        printf("%f\n", ((-b - sqrt(d))) / (2 * (double) a));
    }
    else if (a != 0 && (d > 0)) {
        printf("2\n");
        printf("%f\n", ((-b - sqrt(d))) / (2 * (double) a));
        printf("%f\n", ((-b + sqrt(d))) / (2 * (double) a));
    }
    else if (a == 0 && b == 0 && c != 0) {
        printf("0\n");
    }
    else if (a != 0 && (d) < 0) {
        printf("0\n");
    }
    else if (a == 0 && b == 0 && c == 0) {
        printf("-1\n");
    }
    else if (a == 0) {
        printf("1\n");
        printf("%f\n", (-c / (double) b));
    }
    return 0;
}
