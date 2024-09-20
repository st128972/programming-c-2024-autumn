#include <iostream>

int main(int argc, char *argv[]) {
    int h = 0;
    int a = 0;
    int b = 0;
    scanf("%d", &h);
    scanf("%d", &a);
    scanf("%d", &b);
    int e = 1 + ((h - a) > 0) * ((h - a + (a - b - 1)) / (a - b));
    printf("%d\n", e);
    return EXIT_SUCCESS;
}


