#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<pair<double, int>> v;
    sort(stages.begin(),stages.end());
    for (int i = 1; i<=N; ++i) {
        int tmp = upper_bound(stages.begin(),stages.end(),i)-lower_bound(stages.begin(),stages.end(),i);
        v.push_back({(double) -tmp/stages.size(),i});
        stages.erase(stages.begin(),stages.begin()+tmp);
    }
    sort(v.begin(),v.end());
    vector<int> answer;
    for (auto cur : v) {
        answer.push_back(cur.second);
    }

    return answer;
}