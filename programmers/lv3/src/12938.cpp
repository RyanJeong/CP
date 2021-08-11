#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) 
{
    vector<int> answer;
    if (n>s) {
        answer.push_back(-1);
    }
    else {
        while (n) { // 3 11 -> 3 4 4 
            int sub = s/n--;
            answer.push_back(sub);
            s-=sub;
        }
    }

    return answer;
}