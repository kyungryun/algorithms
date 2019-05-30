#include <cstdio>

int main() {
    int T;
    scanf("%d", &T);
    int ans = 0;

    for (int t = 1; t <= T; t++) {
        int p, q, r, s, w;
        int A, B;
        ans = 0;
        scanf("%d%d%d%d%d", &p, &q, &r, &s, &w);
         
        A = p * w;
        if (w <= r)
            B = q;
        else {
            B = q + s * (w - r);
        }
        if (A < B) ans = A;
        else ans = B;
        printf("#%d %d\n", t, ans);
    }
}
