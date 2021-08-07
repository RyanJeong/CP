#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    stack<int> s;
    int answer = 0;
    for (int i : moves) {
        int col = i-1; // 0-based
        int row = 0;
        while (row<board.size()) {
            if (board[row][col]) {
                break;
            }
            ++row;
        }
        if (row==board.size()) {
            continue;
        }
        if (s.empty()) {
            s.push(board[row][col]);
        }
        else {
            if (s.top()==board[row][col]) {
                s.pop();
                answer+=2;
            }
            else {
                s.push(board[row][col]);
            }
        }
        board[row][col]=0;
    }
    
    return answer;
}