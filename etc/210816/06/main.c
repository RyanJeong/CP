#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Point;

Point *start;

int cmp_coor(const void *, const void *);
int cmp_ccw(const void *, const void *);
int is_ccw(const Point *, const Point *, const Point *);

int main(void)
{
    Point *points;
    int n;
    int i, j;

    scanf("%d", &n); /* n>=3 */
    if (n<3) {

        return 1;
    }

    points=(Point *) malloc(sizeof(Point)*n);
    for (i=0; i<n; ++i) {
        scanf("%d %d",&points[i].x,&points[i].y);
    }

    qsort(points,n,sizeof(Point),cmp_coor);
    start=&points[0];

    for (i=0; i<n; ++i) {
        printf("%d %d\n", points[i].x, points[i].y);
    }


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
    int cond = is_ccw(start,s,t);
    if (cond) {
        /* pos: ccw, neg: cw */
        if (cond>0) {

            return 0;
        }
        else {

            return 1;
        }
    }
    else {
        /* x1==x2 or y1==y2 */
        if (((Point *) s)->x==((Point *) t)->x) {

            return (((Point *) s)->y-((Point *) t)->y);
        }
        else {

            return (((Point *) s)->x-((Point *) t)->x);
        }
    }
}

/* 1: ccw, -1: cw, 0: on the line */
int is_ccw(const Point *a, const Point *b, const Point *c)
{
    long long u1 = b->x-a->x;
    long long v1 = b->y-a->y;
    long long u2 = c->x-b->x;
    long long v2 = c->y-b->y;
    long long tmp = u1*v2-u2*v1;

    return ((tmp>0) ? 1 : (tmp<0) ? -1 : 0);
}