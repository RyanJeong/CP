#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin>>str;
    int len = str.size();
    cout << str.substr(0,len/2) << ' ' << str.substr(len/2);

    return 0;
}