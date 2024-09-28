#include <cstdio>

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
    if ((a == e && b == f && c == g) || (a == e && c == f && b == g) || (b == e && a == f && c == g)) {
        printf("Boxes are equal\n");
    }
    else if ((b == e && c == f && a == g) || (c == e && a == f && b == g) || (c == e && b == f && a == g)) {
        printf("Boxes are equal\n");
    }
    else if ((a >= e && b >= f && c >= g) || (a >= e && c >= f && b >= g) || (c >= e && a >= f && b >= g)) {
        printf("The first box is larger than the second one\n");
    }
    else if ((c >= e && b >= f && a >= g) || (b >= e && c >= f && a >= g) || (b >= e && a >= f && c >= g)) {
        printf("The first box is larger than the second one\n");
    }
    else if ((a <= e && b <= f && c <= g) || (a <= e && c <= f && b <= g) || (c <= e && a <= f && b <= g)) {
        printf("The first box is smaller than the second one\n");
    }
    else if ((c <= e && b <= f && a <= g) || (b <= e && c <= f && a <= g) || (b <= e && a <= f && c <= g)) {
        printf("The first box is smaller than the second one\n");
    }
    else {
        printf("Boxes are incomparable\n");
    }
    return 0;
}
