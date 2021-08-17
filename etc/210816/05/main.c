#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **arr; /* 2D array */
int **areas;
int n;     

void dfs(int, int, int);
int cmp(const void *, const void *);

int main(void)
{
    int *res;
    int i, j;
    int cnt = 0;

    scanf("%d",&n); /* range: 5 ~ 25 */
    if (n<5 || n>25) {

        return 1;
    }

    arr=(int **) malloc(sizeof(int *)*n);
    *arr=(int *) malloc(sizeof(int)*n*n);
    for (i=1; i<n; ++i) {
        arr[i]=arr[0]+n*i;
    }
    for (i=0; i<n; ++i) {
        for (j=0; j<n; ++j) {
            scanf("%1d",&arr[i][j]);
        }
    }
    areas=(int **) malloc(sizeof(int *)*n);
    *areas=(int *) malloc(sizeof(int)*n*n);
    for (i=1; i<n; ++i) {
        areas[i]=areas[0]+n*i;
    }
    memset(*areas,-1,sizeof(int)*n*n);

    for (i=0; i<n; ++i) {
        for (j=0; j<n; ++j) {
            if (!arr[i][j] || areas[i][j]!=-1) {
                continue;
            }
            dfs(i,j,cnt++);
        }
    }

    res=(int *) malloc(sizeof(int)*cnt);
    memset(res,0,sizeof(int)*cnt);
    for (i=0; i<n; ++i) {
        for (j=0; j<n; ++j) {
            if (areas[i][j]==-1) {
                continue;
            }
            ++res[areas[i][j]];
        }
    }

    qsort(res,cnt,sizeof(int),cmp);
    printf("%d\n",cnt);
    for (i=0; i<cnt; ++i) {
        printf("%d\n", res[i]);
    }

    free(res);
    free(*areas);
    free(areas);
    free(*arr);
    free(arr);

    return 0;
}

void dfs(int i, int j, int area)
{
    static const int dx[] = {1,0,-1,0};
    static const int dy[] = {0,-1,0,1};
    int d = sizeof dx/sizeof(int);

    areas[i][j]=area;
    while (d--) {
        int x = i+dx[d];
        int y = j+dy[d];

        if (x<0 || x>=n) {
            continue;
        }
        if (y<0 || y>=n) {
            continue;
        }
        if (!arr[x][y] || areas[x][y]!=-1) {
            continue;
        }
        dfs(x,y,area);
    }

    return;
}

int cmp(const void *s, const void *t)
{
    
    return (*(int *) s-*(int *) t);
}