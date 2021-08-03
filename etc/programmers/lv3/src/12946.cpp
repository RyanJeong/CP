#include <string>
#include <vector>

using namespace std;

void move(int from, int to, int n);
    
vector<vector<int>> answer;

vector<vector<int>> solution(int n) 
{
    move(1,3,n);
    
    return answer;
}

void move(int from, int to, int n)
{
    if (n==1) {
        answer.push_back({from,to});
    } 
    //a+b+c=6
    else {
        move(from,6-from-to,n-1);
        answer.push_back({from,to});
        move(6-from-to,to,n-1);
    }

    return;
}