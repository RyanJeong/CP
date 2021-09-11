#include <iostream>
/////
#include <string>
#include <vector>

using namespace std;

vector<int> apeach;
vector<int> ryan;
vector<int> answer = {-1};
int score = 0;

void bt(int n)
{
    int s_ryan = 0;
    int s_apeach = 0;
    for (int i = 0; i<=10; ++i) {
        if (ryan[i]>apeach[i]) {
            if (ryan[i]) {
                s_ryan+=10-i;
            }
        }    
        else {
            if (apeach[i]) {
                s_apeach+=10-i;
            }
        }
    }
    if (s_ryan+10*n<score) {

        return;
    }
    if (!n && s_ryan>s_apeach && s_ryan>=score) {
        /*
        if (answer.front()==-1) {
            answer=ryan;
        }
        else {
            bool is_satisfied = true;
            for (int i = 9; i>=0; --i) {
                if (answer[i]!=ryan[i]) {
for (auto cur : answer) {
    cout << cur << ' ';
}
cout << '\n';
cout << answer[i] << ' ' << ryan[i] << ' ' << s_ryan << '\n';
                    is_satisfied=(answer[i]>ryan[i]) ? false : true;
                    break;
                }
            }
            if (is_satisfied) {
                answer=ryan;
            }
        }
        */
        answer=ryan;
        score=s_ryan;

        return;
    }
    for (int i = 0; i<=10; ++i) {
        if (ryan[i]>apeach[i]) {
            continue;
        }
        ++ryan[i];
        bt(n-1);
        --ryan[i];
    }

    return;
}

vector<int> solution(int n, vector<int> info) 
{
    apeach=info;
    ryan=vector<int>(11);
    bt(n);

    return answer;
}
/////

int main(void)
{
    for (auto cur : solution(1, {1,0,0,0,0,0,0,0,0,0,0})) {
        cout << cur << ' ';
    }
    cout << '\n';
    for (auto cur : solution(5, {2,1,1,1,0,0,0,0,0,0,0})) {
        cout << cur << ' ';
    }
    cout << '\n';

    return 0;
}