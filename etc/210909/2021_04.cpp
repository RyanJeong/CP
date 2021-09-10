#include <iostream>
///////////////////
#include <string>
#include <vector>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) 
{
    vector<vector<int>> d(n+1,vector<int>(n+1));
    fill(d.begin(),d.end(),vector<int>(n+1,1e9));
    for (int i = 1; i<=n; ++i) {
        d[i][i]=0;
    }
    for (auto cur : fares) {
        int a, b, c;
        a=cur[0];
        b=cur[1];
        c=cur[2];
        d[a][b]=min(d[a][b],c);
        d[b][a]=min(d[b][a],c);
    }

    for (int k = 1; k<=n; ++k) {
        for (int i = 1; i<=n; ++i) {
            for (int j = 1; j<=n; ++j) {
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }

    int answer = 1e9;
    for (int k = 1; k<=n; ++k) {
        if (d[s][k]==1e9 || d[k][a]==1e9 || d[k][b]==1e9) {
            continue;
        }
        answer=min(answer,d[s][k]+d[k][a]+d[k][b]);
    }

    return answer;
}
//////////////////

int main(void)
{
    std::cout << solution(6,4,6,2,
        {{4, 1, 10}, 
         {3, 5, 24}, 
         {5, 6, 2}, 
         {3, 1, 41}, 
         {5, 1, 24}, 
         {4, 6, 50}, 
         {2, 4, 66}, 
         {2, 3, 22}, 
         {1, 6, 25}}) << std::endl;
    std::cout << solution(7,3,4,1,
        {{5, 7, 9}, 
         {4, 6, 4}, 
         {3, 6, 1}, 
         {3, 2, 3}, 
         {2, 1, 6}}) << std::endl;
    std::cout << solution(6,4,5,6,
        {{2,6,6}, 
         {6,3,7}, 
         {4,6,7}, 
         {6,5,11}, 
         {2,5,12}, 
         {5,3,20}, 
         {2,4,8}, 
         {4,3,9}}) << std::endl;

    return 0;
}