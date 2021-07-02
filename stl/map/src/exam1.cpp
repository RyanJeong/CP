#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    map<string, int> m; // key: string, value: int
    m["Jeong"]=123456; // { { "Jeong", 123456 } }
    m["Oh"]=234567; // { { "Jeong", 123456 }, { "Oh", 234567 } }
    m["Park"]=345678; // { { "Jeong", 123456 }, { "Oh", 234567 }, { "Park", 345678 } }
    for (auto e: m) {
        cout << e.first << ' ' << e.second << '\n';
        /*
            Jeong 123456
            Oh 234567
            Park 345678
        */
    }

    m["Park"]=876543; // { { "Jeong", 123456 }, { "Oh", 234567 }, { "Park", 876543 } }
    cout << m["Park"] << '\n'; // 876543

    m.erase("QWERT"); // nop
    m.erase("Park"); // { { "Jeong", 123456 }, { "Oh", 234567 } }
    for (auto e: m) {
        cout << e.first << ' ' << e.second << '\n';
        /*
            Jeong 123456
            Oh 234567
        */
    }
    m.clear();

    multimap<int, string> ms;
    ms.insert({1, "Hi" });  // { { 1, "Hi" } }
    ms.insert({1, "Hello" }); // { { 1, "Hi" }, { 1, "Hello" } }
    ms.insert({2, "Bye" }); // { { 1, "Hi" }, { 1, "Hello" }, { 2, "Bye" } }

    for (auto e: ms) {
        cout << e.first << " " << e.second << '\n';
        /*
            1 Hi
            1 Hello
            2 Bye
        */
    }

    return 0;
}