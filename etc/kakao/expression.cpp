// https://programmers.co.kr/learn/courses/30/lessons/67257
#include <bits/stdc++.h>

using namespace std;

long long solution(string expression) {
  long long         answer = 0;
  vector<char>      op = { '+', '-', '*' };
  vector<long long> nums;
  vector<char>      ops;
  string            temp;

  sort(op.begin(), op.end());
  for (char c : expression) {
    if (c == '+' || c == '-' || c == '*') {
      ops.push_back(c);
      nums.push_back(atoi(temp.c_str()));
      temp = "";
    } else {
      temp += c;
    }
  }
  long long op1, op2, res;

  op1 = op2 = res = 0;
  nums.push_back(atoi(temp.c_str()));
  do {
    vector<long long> temp_nums(nums);
    vector<char>      temp_ops(ops);

    for (char c : op) {
      unsigned i = 0;
      
      while (i < temp_ops.size()) {
        if (temp_ops[i] == c) {
          op1 = temp_nums[i];
          temp_nums.erase(temp_nums.begin() + i);
          op2 = temp_nums[i];
          temp_nums.erase(temp_nums.begin() + i);
          temp_ops.erase(temp_ops.begin() + i);
          res = (c == '+' ? op1 + op2 : (c == '-' ? op1 - op2 : op1 * op2));
          temp_nums.insert(temp_nums.begin() + i, res);
        } else {
          ++i;
        }
      }
    }
    answer = max(answer, abs(res));
  } while (next_permutation(op.begin(), op.end()));

  return answer;
}

//
int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string expression = "100-200*300-500+20";
  cout << solution(expression);

  return 0;
}
