#include<cstdio>
int a[300], n, m;
bool f(int l) {
    int s = 0, c = 1;
    for (int i = 0; i < n; i++) {
        s += a[i];
        if (s > l) s = a[i], c++;
    }
    return c <= m;
}
int main() {
    scanf("%d%d", &n, &m);
    int low = 0, up = 30000, mid;
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
        if (a[i] > low) low = a[i];
    }
    while (low <= up) {
        mid = (low + up) / 2;
        printf("H: %d, L: %d, M: %d\n", up, low, mid);
        f(mid) ? up = mid - 1 : low = mid + 1;
    }
    printf("%d\n", low);
    int i = 0, s = 0, t = 0;
    for (; i < n; i++) {
        s += a[i];
        if (s > low) {
            s = a[i];
            m--;
            printf("%d ", t);
            t = 0;
        }
        t++;
        if (n - i == m) break;
    }
    while (m--) printf("%d ", t), t = 1;
    return 0;
}