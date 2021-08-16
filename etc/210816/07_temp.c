#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAGNITUDE(v) (v[1]*v[1] + v[2]*v[2] + v[3]*v[3])

int main(void)
{
    /* 1-based for readability */
    double a[4][4];
    double u[4][4], u_product[4], proj, tmp;
    double q[4][4], r[4][4];
    int n = 3;
    int i, j, k;

    /* invertible matrix A: 
        {{1, 0, 0}, 
         {1, 1, 0}, 
         {1, 1, 1}} */
    a[1][1]=1, a[1][2]=0, a[1][3]=0;
    a[2][1]=1, a[2][2]=1, a[2][3]=0;
    a[3][1]=1, a[3][2]=1, a[3][3]=1;


    /* u_1 */
    for (i=1; i<=n; ++i) {
        u[i][1]=a[i][1];
    }

    /* u_2 = a_2 - proj_(u_1)a_2*u_1 */
    for (i=1; i<=n; ++i) {
        u[i][2]=a[i][2];
    }
    proj=0.0;
    /* a_2 x u_1 */
    for (i=1; i<=n; ++i) {
        proj+=a[i][2]*u[i][1];
    }
    /* |u|^2 */
    proj/=(u[1][1]*u[1][1]+u[2][1]*u[2][1]+u[3][1]*u[3][1]);
    /* a - proj*u */
    for (i=1; i<=n; ++i) {
        u[i][2]-=proj*u[i][1];
    }

    /* u_3 = a_3 - proj_(u_1)a_3*u_1 - proj_(u_2)a_3*u_2 */
    for (i=1; i<=n; ++i) {
        u[i][3]=a[i][3];
    }
    proj=0.0;
    for (i=1; i<=n; ++i) {
        proj+=a[i][3]*u[i][1];
    }
    proj/=(u[1][1]*u[1][1]+u[2][1]*u[2][1]+u[3][1]*u[3][1]);
    for (i=1; i<=n; ++i) {
        u[i][3]-=proj*u[i][1];
    }
    proj=0.0;
    for (i=1; i<=n; ++i) {
        proj+=a[i][3]*u[i][2];
    }
    proj/=(u[1][2]*u[1][2]+u[2][2]*u[2][2]+u[3][2]*u[3][2]);
    for (i=1; i<=n; ++i) {
        u[i][3]-=proj*u[i][2];
    }

    /* q1 = u1 over |u1| */
    tmp=sqrt((u[1][1]*u[1][1]+u[2][1]*u[2][1]+u[3][1]*u[3][1]));
    for (i=1; i<=n; ++i) {
        q[i][1]=u[i][1]/tmp;
    }
    /* q2 = u2 over |u2| */
    tmp=sqrt((u[1][2]*u[1][2]+u[2][2]*u[2][2]+u[3][2]*u[3][2]));
    for (i=1; i<=n; ++i) {
        q[i][2]=u[i][2]/tmp;
    }
    /* q3 = u3 over |u3| */
    tmp=sqrt((u[1][3]*u[1][3]+u[2][3]*u[2][3]+u[3][3]*u[3][3]));
    for (i=1; i<=n; ++i) {
        q[i][3]=u[i][3]/tmp;
    }
    puts("Q:");
    for (i=1; i<=n; ++i) {
        for (j=1; j<=n; ++j) {
            printf("%6.3f ",q[i][j]);
        }
        putchar('\n');
    }

/*
    for (i=1; i<=n; ++i) {
        for (j=1; j<=n; ++j) {
            if (i>j) {
                r[i][j]=0.0;
            }
            else {
                r[i][j]=INNER_PRODUCT(a[i],q[j]);
            }
        }
    }
    puts("R:");
    for (i=1; i<=n; ++i) {
        for (j=1; j<=n; ++j) {
            printf("%6.3f ",r[i][j]);
        }
        putchar('\n');
    }
    */

    return 0;
}