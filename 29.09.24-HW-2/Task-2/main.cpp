#include<cstdio>

int main(int argc, char *argv[]) {
    int a = 0;
    int b = 0;
    scanf("%d", &a);
    scanf("%d", &b);
    if (a == 1 && b == 1) {
        printf("0");
    }
    else if (a == 1 || b == 1 || a != b) {
        printf("1");
    }
    else {
        printf("2");
    }

    return 0;
}
