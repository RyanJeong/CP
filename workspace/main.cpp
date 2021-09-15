#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    int next = 1;
    while (n--) {
        string str;
        cin>>str;
        if (str!="mumble") {
            if (next!=stoi(str)) {
                cout << "something is fishy";

                return 0;
            }
        }
        ++next;
    }
    cout << "makes sense";

    return 0;
}