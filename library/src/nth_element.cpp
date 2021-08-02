#include <algorithm>
#include <vector>

using namespace std;

int kth(vector<int>& a, int k) 
{
    nth_element(a.begin(),a.begin()+k-1,a.end()); // 0-based
    
    return a[k-1];
}