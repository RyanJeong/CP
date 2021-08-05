#include <vector>

using namespace std;

int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) 
{
    for (int i = 0; i<city_map.size(); ++i) {
        city_map[i].insert(city_map[i].begin(),0);
    }
    city_map.insert(city_map.begin(),vector<int>(n+1));

    vector<vector<int>> dp_down(m+1,vector<int>(n+1));
    vector<vector<int>> dp_right(m+1,vector<int>(n+1));
    dp_down[1][1]=dp_right[1][1]=1; // city_map[1][1]=0

    for (int i = 1; i<=m; ++i) {
        for (int j = 1; j<=n; ++j) {
            if (city_map[i][j]==0) {
                dp_down[i][j]+=(dp_down[i-1][j]+dp_right[i][j-1])%MOD;
                dp_right[i][j]+=(dp_down[i-1][j]+dp_right[i][j-1])%MOD;
            }
            else if (city_map[i][j]==1) {
                dp_down[i][j]=dp_right[i][j]=0;
            }
            else { // city_map[i][j]==2
                dp_down[i][j]=dp_down[i-1][j];
                dp_right[i][j]=dp_right[i][j-1];
            }
        }
    }

    return dp_down[m][n]%MOD;
}