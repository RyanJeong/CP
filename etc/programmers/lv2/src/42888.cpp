#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) 
{
    map<string, string> m;
    vector<pair<string, char>> v;
    for (string s : record) {
        char op = s[0];
        if (op=='E' || op=='L') {
            s.erase(0,6);
        }
        else if (op=='C') {
            s.erase(0,7);
        }

        string id;
        for (char c : s) {
            if (c==' ') {
                break;
            }
            id.push_back(c);
        }
        s.erase(0,id.size()+1);

        if (op!='L') {
            string nick = s;
            m[id]=nick;
        }
        
        if (op!='C') {
            v.push_back({id,op});
        }
    }

    vector<string> answer;
    for (auto cur : v) {
        if (cur.second=='E') {
            answer.push_back(m[cur.first]+"님이 들어왔습니다.");
        }
        else {
            answer.push_back(m[cur.first]+"님이 나갔습니다.");
        }
    }

    return answer;
}