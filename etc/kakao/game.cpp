// https://programmers.co.kr/learn/courses/30/lessons/64061
#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
  int        answer = 0;
  int        size   = board.size();
  stack<int> s;
  
  for (unsigned i = 0; i < moves.size(); ++i) {
    int col = moves[i] - 1; // for 1-based index
    int row = 0;
    
    while (row < size) {
      if (board[row][col]) {
        break;
      }
      ++row;
    }
    if (row == size) {
      continue;
    }
    if (s.empty()) {
      s.push(board[row][col]);
    } else {
      if (s.top() == board[row][col]) {
        s.pop();
        answer += 2;
      } else {
        s.push(board[row][col]);
      }
    }
    board[row][col] = 0;
  }
  
  return answer;
}

int main(void)
{
  vector<vector<int>> board = {{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
  vector<int> moves = {1,5,3,5,1,2,1,4};

  cout << solution(board, moves);

  return 0;
}