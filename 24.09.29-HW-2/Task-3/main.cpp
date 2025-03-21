#include <cstdio>
#include <cmath>

int main(int argc, char *argv[]) {
    int a = 0;
    int b = 0;
    int c = 0;
    int e = 0;
    int f = 0;
    int g = 0;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &e);
    scanf("%d", &f);
    scanf("%d", &g);
    int d = pow((a - e) + (b - f), 2);
    int i = sqrt(d);
    if (i > (c + g) || i < abs(c - g)) {
        printf("NO\n");
    }
    else {
        printf("YES\n");
    }


    return 0;
}
