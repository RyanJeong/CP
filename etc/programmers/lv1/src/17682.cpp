#include <string>
#include <stack>

using namespace std;

int solution(string dartResult) 
{
    int tmp = 0;
    stack<int> s;
    s.push(0);
    for (char c : dartResult) {
        if (isdigit(c)) {
            tmp=tmp*10+c-'0';
        }
        else if (isalpha(c)) {
            switch (c) {
            case 'S':
                tmp=tmp;
                break;
            case 'D':
                tmp=tmp*tmp;
                break;
            case 'T':
                tmp=tmp*tmp*tmp;
                break;
            default:
                break;
            }
            s.push(tmp);
            tmp=0;
        }
        else { // '#' or '*'
            if (c=='#') {
                int op = s.top();
                s.pop();
                s.push(-op);
            }
            else if (c=='*') {
                int op1 = s.top();
                s.pop();
                int op2 = s.top();
                s.pop();
                s.push(op2*2);
                s.push(op1*2);
            }
        }
    }

    int answer = 0;
    while (!s.empty()) {
        answer+=s.top();
        s.pop();
    }

    return answer;
}