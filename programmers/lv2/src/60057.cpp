#include <string>
#include <vector>

using namespace std;

int solution(string s) 
{
    int answer = s.size();
    for (int i = 1; i<=s.size()/2; ++i) {
        string tmp = s.substr(0,i);
        int freq = 1;
        string result;
        for (int j = i; j<s.size(); j+=i) {
            if (tmp==s.substr(j,i)) {
                ++freq;
            }
            else {
                if (freq>1) {
                    result+=to_string(freq);
                    freq=1;
                }
                result+=tmp;
                tmp=s.substr(j,i);
            }
        }
        if (freq>1) {
            result+=to_string(freq);
        }
        result+=tmp;
        answer=min(answer,(int) result.size());
    }

    return answer;
}
