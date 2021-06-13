#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    set<int> s;
    s.insert(3); // { 3 }
    s.insert({ 5, 1, 7 }); // { 1, 3, 5, 7 }

    if (s.find(6)==s.end()) {
        cout << "6 is not in 's'\n"; // print it
    } 
    else {
        cout << "6 is in 's'\n";
    }
    cout << s.size() << '\n'; // 4

    s.erase(2); // nop
    s.erase(1); // { 3, 5, 7 }
    s.insert(3); // not allowed dup., { 3, 5, 7 }
    for (auto i : s) {
        cout << i << ' ';
    }
    cout << '\n';
    s.clear();

    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    cout << ms.count(1) << '\n'; // { 1, 1, 1 }, => 3

    return 0;
}