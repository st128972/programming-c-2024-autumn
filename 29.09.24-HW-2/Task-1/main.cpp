#include <cstdio>

int main(int argc, char *argv[]) {
    int a = 0;
    int b = 0;
    int c = 0;
    int e = 0;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &e);
    if (a == c || b == e || a - c == b - e) {
        printf("YES\n");
    }
    else if (a - c == e - b || c - a == e - b || c - a == b - e) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
    return 0;
}
