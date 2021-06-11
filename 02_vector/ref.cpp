#include <bits/stdc++.h>
using namespace std;

int main(void) 
{
    vector<int> v1(3,5); // {5,5,5};

    cout << v1.size() << '\n'; // 3
    v1.push_back(7); // {5,5,5,7};
    //-----------------------------------------
    vector<int> v2(2); // {0,0};

    v2.insert(v2.begin()+1,3); // {0,3,0};
    //-----------------------------------------
    vector<int> v3 = {1,2,3,4}; // {1,2,3,4}

    v3.erase(v3.begin()+2); // {1,2,4};
    //-----------------------------------------
    vector<int> v4; // {}

    v4=v3; // {1,2,4}
    cout << v4[0] << v4[1] << v4[2] << '\n';
    v4.pop_back(); // {1,2}
    v4.clear(); // {}
    //-----------------------------------------
    vector<int> v5={1,2,3,4,5};
    for (int i : v5) {
        cout << i << ' ';
    }
    cout << '\n';
    v5.erase(v5.begin()+1); // { 1,3,4,5 }
    for (int i : v5) {
        cout << i << ' ';
    }
    cout << '\n';
    v5.erase(v5.begin()+1); // { 1,4,5 }
    for (int i : v5) {
        cout << i << ' ';
    }
    cout << '\n';
    v5.insert(v5.begin()+1,6); // { 1,6,4,5 }
    for (int i : v5) {
        cout << i << ' ';
    }
    cout << '\n';
    //-----------------------------------------
    vector<int> v6(v5);
    v5.erase(v5.begin());
    for (int i : v5) {
        cout << i << ' ';
    }
    cout << '\n';
    for (int i : v6) {
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}