#include <iostream>

int main(int argc, char* argv [])
{
    int a = 0;
    int b = 0;
    scanf("%d", &a);
    scanf("%d", &b);
    int c = (a * b + 109000000) % 109 + 1;
    printf("%d\n", c);
    return EXIT_SUCCESS;
}
