/*
  Copyright 2024 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

#include <stdio.h>

int main(void) {
  int n;

  scanf("%d ", &n);
  while (n--) {
    char c, prev;

    while ((c = getchar()) != EOF) {
      if (c == '\n') break;
      putchar(c);
      prev = c;
    }
    if (prev != '.') putchar('.');
    putchar(c);
  }

  return 0;
}
