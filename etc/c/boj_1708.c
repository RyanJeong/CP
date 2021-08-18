// https://www.acmicpc.net/problem/1708
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Point;

Point *start;

int cmp_coor(const void *, const void *);
int cmp_ccw(const void *, const void *);
long long ccw(const Point *, const Point *, const Point *);

int main(void)
{
    Point *points, *buf, p1, p2;
    int buf_size;
    int n;
    int i;

    scanf("%d", &n); /* n>=3 */
    points=(Point *) malloc(sizeof(Point)*n);
    for (i=0; i<n; ++i) {
        scanf("%d %d",&points[i].x,&points[i].y);
    }

    /* 1. sort */
    qsort(points,n,sizeof(Point),cmp_coor);
    start=&points[0];
    qsort(points+1,n-1,sizeof(Point),cmp_ccw);

    /* 2. Graham scan */
    buf=(Point *) malloc(sizeof(Point)*n);
    buf_size=0;
    buf[buf_size++]=points[0];
    buf[buf_size++]=points[1];
    for (i=2; i<n; ++i) {
        while (buf_size>=2) {
            p2=buf[--buf_size];
            p1=buf[buf_size-1];
            if (ccw(&p1,&p2,&points[i])>0) {
                buf[buf_size++]=p2;
                break;
            }
        }
        buf[buf_size++]=points[i];
    }
    printf("%d\n", buf_size);

    free(buf);
    free(points);

    return 0;
}

int cmp_coor(const void *s, const void *t)
{
    if (((Point *) s)->y<((Point *) t)->y) {

        return 0;
    }
    else if (((Point *) s)->y==((Point *) t)->y && ((Point *) s)->x<((Point *) t)->x) {

        return 0;
    }
    else {

        return 1;
    }
}

int cmp_ccw(const void *s, const void *t)
{
    long long cond = ccw(start,s,t);

    if (cond) {
        /* pos: ccw, neg: cw */

        return cond<0;
    }
    else {
        /* x1==x2 or y1==y2 */
        
        return ((Point *) s)->x+((Point *) s)->y>((Point *) t)->x+((Point *) t)->y;
    }
}

/* 1: ccw, -1: cw, 0: on the line */
long long ccw(const Point *a, const Point *b, const Point *c)
{
    long long u1 = b->x-a->x;
    long long v1 = b->y-a->y;
    long long u2 = c->x-b->x;
    long long v2 = c->y-b->y;
    
    return u1*v2-u2*v1;
}