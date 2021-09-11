#include <iostream>
///// WIP
#include <string>
#include <vector>

using namespace std;

vector<int> left_child;
vector<int> right_child;
vector<int> type;
int answer = 1;

// DFS
void preorder(int cur)
{
    cout << cur << ' ';
    if (left_child[cur]!=-1) {
        preorder(left_child[cur]);
    }
    if (right_child[cur]!=-1) {
        preorder(right_child[cur]);
    }

    return;
}

int solution(vector<int> info, vector<vector<int>> edges) 
{
    int n_edge = edges.size();
    left_child=vector<int>(n_edge+1,-1);
    right_child=vector<int>(n_edge+1,-1);
    type=info;
    for (auto e : edges) {
        int u = e.front();
        int v = e.back();
        if (left_child[u]==-1) {
            left_child[u]=v;
        }
        else {
            right_child[u]=v;
        }
    }
    preorder(0);

    return answer;
}
/////

int main(void)
{
    cout << solution({0,0,1,1,1,0,1,0,1,0,1,1},{{0,1},{1,2},{1,4},{0,8},{8,7},{9,10},{9,11},{4,3},{6,5},{4,6},{8,9}}) << '\n';
    cout << solution({0,1,0,1,1,0,1,0,0,1,0},{{0,1},{0,2},{1,3},{1,4},{2,5},{2,6},{3,7},{4,8},{6,9},{9,10}}) << '\n';
    return 0;
}