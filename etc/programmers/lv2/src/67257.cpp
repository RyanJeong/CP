#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(string expression) 
{
    vector<char> op;
    vector<long long> num;
    int tmp = 0;
    for (char c : expression) {
        if (c=='+' || c=='-' || c=='*') {
            op.push_back(c);
            num.push_back(tmp);
            tmp=0;
        }
        else {
            tmp=tmp*10+c-'0';
        }
    }
    num.push_back(tmp);

    vector<char> priority = {'+','-','*'};
    sort(priority.begin(),priority.end());
    long long answer = 0;
    do {
        vector<char> tmp_op(op);
        vector<long long> tmp_num(num);
        for (char p_op : priority) {
            int i = 0;
            while (i<tmp_op.size()) {
                if (tmp_op[i]==p_op) {
                    if (p_op=='+') {
                        tmp_num[i]+=tmp_num[i+1];
                    }
                    else if (p_op=='-') {
                        tmp_num[i]-=tmp_num[i+1];
                    }
                    else if (p_op=='*') {
                        tmp_num[i]*=tmp_num[i+1];
                    }
                    tmp_num.erase(tmp_num.begin()+i+1);
                    tmp_op.erase(tmp_op.begin()+i);
                }
                else {
                    ++i;
                }
            }
        }
        answer=max(answer,abs(tmp_num[0]));
    } while (next_permutation(priority.begin(),priority.end()));

    return answer;
}