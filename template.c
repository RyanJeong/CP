/*
  Copyright 2024 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

#include <stdio.h>

#ifdef CP_MSJEONG_DEBUG
#define dprintf(format, ...) fprintf(stderr, format, __VA_ARGS__)
#else
#define dprintf(...)
#endif

#define ABS(x)    ((x) * ((x > 0) - (x < 0)))
#define MIN(x, y) (x > y ? y : x)
#define MAX(x, y) (x < y ? y : x)

int main(void)
{
  return 0;
}
