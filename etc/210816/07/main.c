#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 3

int main(void)
{
    /* 1-based for readability */
    double a[SIZE+1][SIZE+1];
    double u[SIZE+1][SIZE+1], u_product[SIZE+1], proj, tmp;
    double q[SIZE+1][SIZE+1], r[SIZE+1][SIZE+1];
    int n = SIZE;
    int i, j, k;

    /* matrix A: 
        {{1, 0, 0}, 
         {1, 1, 0}, 
         {1, 1, 1}} */
    a[1][1]=1, a[1][2]=0, a[1][3]=0;
    a[2][1]=1, a[2][2]=1, a[2][3]=0;
    a[3][1]=1, a[3][2]=1, a[3][3]=1;

    /* Gram-Schmidt */
    for (i=1; i<=n; ++i) {
        for (j=1; j<=n; ++j) {
            u[j][i]=a[j][i];
        }
        for (j=1; j<i; ++j) {
            proj=0.0;
            for (k=1; k<=n; ++k) {
                proj+=a[k][i]*u[k][j];
            }
            proj/=u_product[j];
            for (k=1; k<=n; ++k) {
                u[k][i]-=proj*u[k][j];
            }
        }
        u_product[i]=0.0;
        for (j=1; j<=n; ++j) {
            u_product[i]+=u[j][i]*u[j][i];
        }
    }

    /* normalize and get Q and R */
    for (i=1; i<=n; ++i) {
        tmp=sqrt(u_product[i]);
        for (j=1; j<=n; ++j) {
            q[j][i]=u[j][i]/tmp;
        }
    }
    for (i=1; i<=n; ++i) {
        for (j=1; j<=n; ++j) {
            r[i][j]=0.0;
            if (i>j) {
                continue;
            }
            for (k=1; k<=n; ++k) {
                r[i][j]+=a[k][j]*q[k][i];
            }
        }
    }

    puts("Q:");
    for (i=1; i<=n; ++i) {
        for (j=1; j<=n; ++j) {
            printf("%6.3f ",q[i][j]);
        }
        putchar('\n');
    }
    puts("R:");
    for (i=1; i<=n; ++i) {
        for (j=1; j<=n; ++j) {
            printf("%6.3f ",r[i][j]);
        }
        putchar('\n');
    }

    return 0;
}