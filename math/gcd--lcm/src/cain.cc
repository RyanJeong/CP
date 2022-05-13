/*
  Copyright 2022 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/
/*
식 A ≡ B(mod m) 은 A와 B가 M으로 나눈 나머지가 같음을 의미

A ≡ B (mod m) 일 때
1. A + C ≡ B + C (mod m)
2. A - C ≡ B - C (mod m)
3. AC ≡ BC (mod m)
4. A ÷ C ≡ B ÷ C (mod m)은 성립하지 않음 ( A=6, B=2, C=2, M=4 )
    
    A ≡ x (mod M), A ≡ y (mod N)
 -> (x + M | x + 2M | ... ) ≡ y (mod N)
*/

// CP
#define CP do {                     \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(NULL);               \
} while (0)

#include <iostream>

using std::cin;
using std::cout;

int main() {
  CP;

  int t;
  cin >> t;
  while (t--) {
    int m, n, x, y;
    cin >> m >> n >> x >> y;
    if (y == n)
      y = 0;
    int res = -1;
    for (int i = x; i <= m * n; i += m) {
      if (i % n == y) {
        res = i;
        break;
      }
    }
    cout << ((res < 0) ? -1 : res) << '\n';
  }

  return 0;
}
