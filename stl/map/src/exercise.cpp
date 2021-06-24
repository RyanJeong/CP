#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    map<string, int> m; // key: string, value: int
    m["Jeong"] = 123456;
    m["Oh"]    = 234567;
    m["Park"]  = 345678;

    for (auto e: m) {
    /*
        Jeong 123456
        Oh 234567
        Park 345678
    */
        cout << e.first << ' ' << e.second << '\n';
    }

    m["Park"]=876543;
    cout << m["Park"] << '\n'; // 876543

    m.erase("QWERT"); // nop
    m.erase("Park");
    for (auto e: m) {
    /*
        Jeong 123456
        Oh 234567
    */
        cout << e.first << ' ' << e.second << '\n';
    }
    m.clear();

    multimap<int, string> ms;
    ms.insert({ 1, "Hello" });
    ms.insert({ 1, "Hi" });
    ms.insert({ 2, "Bye" });

    for (auto e: ms) {
    /*
        1 Hello
        1 Hi
        2 Bye
    */
        cout << e.first << " " << e.second << '\n';
    }

    return 0;
}