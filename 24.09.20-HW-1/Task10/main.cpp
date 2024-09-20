#include <iostream>

int main(int argc, char* argv[])
{
    int a = 0;
    scanf("%d", &a);
    int x = (2 * a) / 3;
    int y = (a - x) / 2;
    printf("%d", y);
    printf(" ");
    printf("%d", x);
    printf(" ");
    printf("%d\n", y);
    return EXIT_SUCCESS ;
}
