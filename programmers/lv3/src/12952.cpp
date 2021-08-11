#include <string>
#include <vector>

using namespace std;

bool is_used1[15]; // vertical
bool is_used2[30]; // diagonal (y = x)
bool is_used3[30]; // diagonal (y = -x)
int cnt, row;

void rec(int r) 
{
    if (r==row) {
        ++cnt;

        return;
    }
    for (int i = 0; i<row; ++i) {
        if (is_used1[i] || is_used2[i+r] || is_used3[r-i+row-1]) {
            continue;
        }
        is_used1[i]=true;
        is_used2[i+r]=true;
        is_used3[r-i+row-1]=true; // { 3, 0 }, 0 - 3 + 4 - 1 = 0
        rec(r+1);
        is_used1[i]=false;
        is_used2[i+r]=false;
        is_used3[r-i+row-1]=false;
    }

    return;
}

int solution(int n) 
{
    row=n;
    rec(0);
    
    return cnt;
}