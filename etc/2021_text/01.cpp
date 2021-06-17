#include <bits/stdc++.h>

using namespace std;

int solution(string s) 
{
  int answer = 0;
  int size = s.size();

  for (int i = 0; i < size; ++i) {
    if (isdigit(s[i])) {
      answer = (answer * 10) + (s[i] - '0');
    } else {
      int temp = 0;

      switch (s[i]) {
      case 'z':
        temp = 0;
        i    += 2;
        break;
      case 'o':
        temp = 1;
        i    += 2;
        break;
      case 't': // two, three
        temp = (s[i+2] == 'o' ? 2 : 3);
        i    += (s[i+2] == 'o' ? 2 : 4); // two, three
        break;
      case 'f': // four, five
        temp = (s[i+3] == 'r' ? 4 : 5);
        i    += 3;
        break;
      case 's': // six, seven
        temp = (s[i+2] == 'x' ? 6 : 7);
        i    += (s[i+2] == 'x' ? 2 : 4);
        break;
      case 'e': // 5 -> 4
        temp = 8;
        i += 4;
        break;
      case 'n': // 4 -> 3
        temp = 9;
        i += 3;
        break;
      default:
        break;
      }
      answer = (answer * 10) + temp;
    }
  }

  return answer;
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cout << solution("one4seveneight");

  return 0;
}