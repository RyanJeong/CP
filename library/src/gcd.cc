/*
  Copyright 2022 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/
// AB = GL
// AB/G = L

int gcd(int a, int b) {
  return (!b) ? a : gcd(b, a % b);
}
