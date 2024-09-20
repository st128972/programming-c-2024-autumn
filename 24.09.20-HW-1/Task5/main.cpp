#include <iostream>

int main(int argc, char* argv[])
{
    int a = 0;
    scanf("%d", &a);
    int b = a + 1;
    int c = a - 1;
    printf("The next number for the number");
    printf(" ");
    printf("%d", a);
    printf(" ");
    printf("is");
    printf(" ");
    printf("%d", b);
    printf(".\n");
    printf("The previous number for the number");
    printf(" ");
    printf("%d", a);
    printf(" ");
    printf("is");
    printf(" ");
    printf("%d", c);
    printf(".\n");
    return EXIT_SUCCESS;
}
