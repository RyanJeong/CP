#include <iostream>

#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(string p) 
{
    string answer = "";
    if (p.empty()) {

        return answer;
    }

    stack<char> s;
    


    return answer;
}

int main(void)
{
    cout << solution("(()())()") << '\n';
    cout << solution(")(") << '\n';
    cout << solution("()))((()") << '\n';
    cout << solution("") << '\n';

    return 0;
}