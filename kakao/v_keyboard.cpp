// https://programmers.co.kr/learn/courses/30/lessons/67256
#include <iostream>

// --------------

#include <string>
#include <vector>

#define ABS(x) (x * ((x > 0) - (x < 0)))

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";

    int order  = (hand == "right") ? 1 : 0;
    int l_x, l_y, r_x, r_y, x, y, r_dist, l_dist;

    l_x = r_x = 3;
    l_y = 0;
    r_y = 2;
    x      = y      = 0;
    r_dist = l_dist = 0;
    for (auto i : numbers) {
      switch (i) {
      case 1: case 4: case 7:
        answer += 'L';
        l_x = (i == 1 ? 0 : (i == 4) ? 1 : 2);
        l_y = 0;
        break;
      case 3: case 6: case 9:
        r_x = (i == 3) ? 0 : ((i == 6) ? 1 : 2);
        r_y = 2;
        answer += 'R';
        break;
      case 2: case 5: case 8: case 0: // 2-> 1 4 7, 5-> 4 1 7, 8->7
        x      = (i == 2) ? 0 : ((i == 5) ? 1 : ((i == 8) ? 2 : 3));
        y      = 1;
        l_dist = ABS((x - l_x)) + ABS((y - l_y));
        r_dist = ABS((x - r_x)) + ABS((y - r_y));
        if (l_dist > r_dist) {
          answer += 'R';
          r_x = x;
          r_y = y;
        } else if (l_dist < r_dist) {
          answer += 'L';
          l_x = x;
          l_y = y;
        } else {
          answer += (order ? 'R' : 'L');
          r_x = (order ? x : r_x);
          r_y = (order ? y : r_y);
          l_x = (order ? l_x : x);
          l_y = (order ? l_y : y);
        }
        break;
      default:
        break;
      }
      /*
      cout << "digit: " << i << '\n';
      cout << "l_x: " << l_x << ",l_y: " << l_y <<'\n';
      cout << "r_x: " << r_x << ",r_y: " << r_y <<'\n';
      cout << "x: " << x << ",y: " << y <<'\n';
      cout << "r_dist: " << r_dist << ",r_dist: " << r_dist <<'\n';
      cout << answer << '\n' << '\n';
      */
    }

    return answer;
}

// ------------

int main(void)
{
  vector<int> n1 = {1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};
  string s1 = "right";
  vector<int> n2 = {7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2};
  string s2 = "left";
  vector<int> n3 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  string s3 = "right";

  cout << solution(n1, s1) << '\n';
  cout << solution(n2, s2) << '\n';
  cout << solution(n3, s3) << '\n';

  return 0;
}