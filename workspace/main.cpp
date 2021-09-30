#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    while (n--) {
        string str;
        cin>>str;

        auto it = str.end();
        --it;
        string tmp;
        if (*it=='a') {
            tmp="s";
        }
        else if (*it=='i') {
            tmp="os";
        }
        else if (*it=='y') {
            str.erase(it-str.begin());
            tmp="ios";
        }
        else if (*it=='l') {
            tmp="es";
        }
        else if (*it=='n') {
            str.erase(it-str.begin());
            tmp="anes";
        }
        else if (*(it-1)=='n' && *it=='e') {
            str.erase(it-1-str.begin(),2);
            tmp="anes";
        }
        else if (*it=='o') {
            tmp="s";
        }
        else if (*it=='r') {
            tmp="es";
        }
        else if (*it=='t') {
            tmp="as";
        }
        else if (*it=='u') {
            tmp="s";
        }
        else if (*it=='v') {
            tmp="es";
        }
        else if (*it=='w') {
            tmp="as";
        }
        else {
            tmp="us";
        }
        cout << str << tmp << '\n';
    }

    return 0;
}