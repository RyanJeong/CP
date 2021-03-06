#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

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
    Point points[SIZE], buf[SIZE], p1, p2;
    int buf_size;
    int n = SIZE;
    double res = 0.0;
    int i;

    points[0].x=-1, points[0].y=-2;
    points[1].x= 2, points[1].y= 4;
    points[2].x= 5, points[2].y= 3;
    points[3].x= 3, points[3].y= 1;
    points[4].x= 4, points[4].y= 4;
    points[5].x= 6, points[5].y= 2;
    points[6].x=-5, points[6].y=-1;
    points[7].x=-2, points[7].y= 6;

    /* 1. sort */
    qsort(points,n,sizeof(Point),cmp_coor);
    start=&points[0];
    qsort(points+1,n-1,sizeof(Point),cmp_ccw);

    /* 2. Graham scan */
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

    /* 3. calc area */
    for (i=1; i<buf_size-1; ++i) {
        res+=(double) ccw(start,&buf[i],&buf[i+1])/2.0;
    }
    printf("%6.3f\n",res);

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
    long long u2 = c->x-a->x;
    long long v2 = c->y-a->y;
        
    return u1*v2-u2*v1;
}