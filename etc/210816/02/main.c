#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int **arr; /* 2D array */
    int n;     
    int min;   /* minimum number of digits for an intger */
    int len;   /* length of the array */
    int x, y;  /* position of the array */
    int d;     /* direction */
    int cnt;
    int i, j;  

    scanf("%d",&n); /* range: 2 ~ 14 */
    arr=(int **) malloc(sizeof(int *)*n);
    *arr=(int *) malloc(sizeof(int)*n*n);
    for (i=1; i<n; ++i) {
        arr[i]=arr[0]+n*i;
    }
    if (n<5) { /* 16/2 = 8, single digit */
        min=1;
    }
    else {  /* else: two digit */
        min=2;
    }

    len=n;
    d=1;
    x=0;
    y=-1;
    cnt=0;
    while (len) {
        for (i=0; i<len; ++i) {
            y+=d;
            ++cnt;
            arr[x][y]=(cnt&1 ? cnt/2+1 : 0);
        }
        --len;
        for (i=0; i<len; ++i) {
            x+=d;
            ++cnt;
            arr[x][y]=(cnt&1 ? cnt/2+1 : 0);
        }
        d*=-1;
    }

    for (i=0; i<n; ++i) {
        for (j=0; j<n; ++j) {
            printf("%.*d ",min,arr[i][j]);
        }
        putchar('\n');
    }
    free(*arr);
    free(arr);

    return 0;
}