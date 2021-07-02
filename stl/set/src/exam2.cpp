#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    unordered_set<string> us = {"red","green","blue"};
    string color="red";
    auto it = us.find(color);

    if (it==us.end()) {
        cout << "not found.";
    }
    else {
        cout << *it << " is in the container."; // red is in the container.
    }
    cout << '\n';

    unordered_multiset<string> ums = {"red","green","red","blue","green"};
    if (ums.find("red")==ums.end()) {
        cout << "not found.";
    }
    else {
        cout << *ums.find("red") << " found."; // red found.
    }
    cout << '\n';

    return 0;
}