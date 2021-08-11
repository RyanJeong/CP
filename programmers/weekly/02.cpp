#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<vector<int>> scores) 
{
    string answer = "";
    int n = scores.size();
    for (int i = 0; i<n; ++i) {
        int target = scores[i][i];
        vector<int> v;
        for (int j = 0; j<n; ++j) {
            v.push_back(scores[j][i]);
        }
        sort(v.begin(),v.end());
        if (target==v.front() || target==v.back()) {
            int cnt = upper_bound(v.begin(),v.end(),target)-lower_bound(v.begin(),v.end(),target);
            if (cnt==1) {
                v.erase(lower_bound(v.begin(),v.end(),target));
            }
        }

        double sum = 0;
        for (int e : v) {
            sum+=e;
        }
        sum/=v.size();
        if (sum>=90) {
            answer.push_back('A');
        }
        else if (sum>=80) {
            answer.push_back('B');
        }
        else if (sum>=70) {
            answer.push_back('C');
        }
        else if (sum>=50) {
            answer.push_back('D');
        }
        else {
            answer.push_back('F');
        }
    }

    return answer;
}