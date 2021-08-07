#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) 
{
    vector<string> answer;
    for (int i = 0; i<n; ++i) {
        int tmp = (~((~0)<<n)&arr1[i])|(~((~0)<<n)&arr2[i]);
        string s;
        for (int j = 0; j<n; ++j) {
            s.push_back((tmp&1) ? '#' : ' ');
            tmp>>=1;
        }
        reverse(s.begin(),s.end());
        answer.push_back(s);
    }
    return answer;
}