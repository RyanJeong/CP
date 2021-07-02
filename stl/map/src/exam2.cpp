#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    unordered_map<string, double> umap = {
        {"Jeong", 6.1},
        {"Park", 10.4},
        {"Kim", 11.2} 
    };
    string str = "Jeong";
    auto it = umap.find(str);
    if (it==umap.end()) {
        cout << "Not found.";
    }
    else {
        cout << it->first << " is " << it->second; // Jeong is 6.1
    }
    cout << '\n';

    unordered_multimap<string, string> ummap = {
        {"Jeong","C"},
        {"Jeong","C++"},
        {"Kim","Java"},
        {"Oh","Kotlin"}
    };
    cout << ummap.find("Jeong")->second;

    return 0;
}