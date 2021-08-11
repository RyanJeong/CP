#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int price, int money, int count) 
{
    long long tmp = 0;
    for (int i = 1; i<=count; ++i) {
        tmp+=i*price;
    }
    tmp-=money;
    
    return (tmp<0) ? 0 : tmp;
}