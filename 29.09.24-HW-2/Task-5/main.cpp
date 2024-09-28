#include<cstdio>

int main(int argc, char *argv[]) {
    int l1 = 0;
    int w1 = 0;
    int h1 = 0;
    int l2 = 0;
    int w2 = 0;
    int h2 = 0;
    int lc = 0;
    int wc = 0;
    int hc = 0;
    scanf("%d", &l1);
    scanf("%d", &w1);
    scanf("%d", &h1);
    scanf("%d", &l2);
    scanf("%d", &w2);
    scanf("%d", &h2);
    scanf("%d", &lc);
    scanf("%d", &wc);
    scanf("%d", &hc);
    int lm1 = 0;
    int wm1 = 0;
    int lm2 = 0;
    int wm2 = 0;
    int lcm = 0;
    int wcm = 0;

    if (l1 < w1) {
        lm1 = w1;
        wm1 = l1;
    }
    else {
        lm1 = l1;
        wm1 = w1;
    }

    if (l2 < w2) {
        lm2 = w2;
        wm2 = l2;
    }
    else {
        lm2 = l2;
        wm2 = w2;
    }

    if (lc < wc) {
        lcm = wc;
        wcm = lc;
    }
    else {
        lcm = lc;
        wcm = wc;
    }

    if ((h1 + h2) <= hc && lm1 <= lcm && wm1 <= wcm && lm2 <= lcm && wm2 <= wcm) {
        printf("YES");
    }
    else if (lm1 <= lcm && wm1 <= wcm && lm2 <= lcm && wm2 <= wcm && h1 <= hc && h2 <= hc) {
        if (lm1 <= lcm && wm1 <= wcm) {
            if ((lm2 <= (wcm - wm1) && wm2 <= lcm) || (wm2 <= (wcm - wm1) && lm2 <= lcm)) {
                printf("YES");
            }
            else if ((lm2 <= (lcm - lm1) && wm2 <= wcm) || (wm2 <= (lcm - lm1) && lm2 <= wcm)) {
                printf("YES");
            }
            else if (wm1 <= lcm && lm1 <= wcm) {
                if ((lm2 <= (wcm - lm1) && wm2 <= lcm) || (lm2 <= lcm && wm2 <= (wcm - lm1))) {
                    printf("YES");
                }

                else if ((lm2 <= lcm - wm1 && wm2 <= wcm) || (wm2 <= lcm - wm1 && lm2 <= wcm)){
                printf("YES");
                }
                else {
                    printf("NO");
                }
            }
            else {
                printf("NO");
            }

        }
        else {
            printf("NO");
        }
    }
    else {
        printf("NO");
    }


    return 0;
}
