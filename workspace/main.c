#include <stdio.h>
#include <math.h>

int main(void)
{
  int n;

  scanf("%d", &n);
  while (n--) {
    long long x, temp;

    scanf("%lld", &x);
    temp = (long long) sqrt(x);
    temp *= temp;
    printf("%d ", (temp == x) ? 1 : 0); 
  }
  
  return 0;
}