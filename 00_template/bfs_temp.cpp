#include <bits/stdc++.h>

using namespace std;

// for pair
#define X first  
#define Y second

// { x, y }
int  arr[101][101];        // 1: object, 0: none
bool is_visited[101][101]; // 1: true,   0: false

// right -> bottom -> left -> top
int dx[4] = { 1,0,-1,0};
int dy[4] = { 0,1,0,-1}; 

queue<pair<int, int>> q;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
