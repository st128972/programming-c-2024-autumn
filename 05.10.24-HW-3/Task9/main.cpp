#include <cstdio>

int main() {
    long long a = 0;
    long long b = 0;
    long long c = 0;
    long long d = 0;
    scanf("%lld", &a);
    scanf("%lld", &b);
    scanf("%lld", &c);
    scanf("%lld", &d);
    for (int x = -100; x <= 100; ++x) {
        if (a * x * x * x + b * x * x + c * x + d == 0) {
            printf("%d ", x);
        }
    }
    return 0;
}
