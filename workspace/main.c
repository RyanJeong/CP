#include <stdio.h>

int main(void)
{
  int n, i, j;
  
  scanf("%d", &n);
  for (i = 0; i < n + 2; ++i) {
    for (j = 0; j < n + 2; ++j) {
      if (!i || !j || i == n + 1 || j == n + 1)
        putchar('@');
      else
        putchar(' ');
    }
    putchar('\n');
  }

  return 0;
}