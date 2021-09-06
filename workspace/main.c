#include <stdio.h>

int s[100001];

int main(void)
{
    int n, k, i;
    int r = -1e9;

    scanf("%d %d",&n,&k);
    for (i=1; i<k; ++i) {
        scanf("%d",&s[i]);
        s[i]+=s[i-1];
    }
    while (i<=n) {
        scanf("%d",&s[i]);
        s[i]+=s[i-1];
        if (r<s[i]-s[i-k]) {
            r=s[i]-s[i-k];
        }
        ++i;
    }
    printf("%d",r);

    return 0;
}