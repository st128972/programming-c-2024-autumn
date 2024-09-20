#include <iostream>

int main(int argc, char* argv[])
{
    int a = 0;
    scanf("%d", &a);
    int x = a / 100;
    int y = a / 10 %10;
    int z = a % 10;
    int k = x + y + z;
    printf("%d\n",k);
    return EXIT_SUCCESS;
}
