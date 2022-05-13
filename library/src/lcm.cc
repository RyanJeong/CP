/*
  Copyright 2022 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

// AB = GL
// AB/G = L
int gcd(int, int);
int lcm(int, int);

int gcd(int a, int b) {
  return (!b) ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
  return a / gcd(a, b) * b;  // escape overflow
}
