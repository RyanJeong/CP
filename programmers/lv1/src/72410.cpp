#include <string>
#include <vector>

using namespace std;

string solution(string new_id) 
{
    string tmp;

    // step 1
    for (char c : new_id) {
        tmp.push_back((isalpha(c)) ? tolower(c) : c);
    }
    new_id=tmp;
    tmp.clear();

    // step 2
    for (char c : new_id) {
        if (!isalpha(c) && !isdigit(c) && c!='-' && c!='_' && c!='.') {
            continue;
        }
        tmp.push_back(c);
    }
    new_id=tmp;
    tmp.clear();

    // step 3
    bool is_used = false;
    for (char c : new_id) {
        if (c=='.') {
            if (!is_used) {
                is_used=true;
                tmp.push_back(c);
            }
        } 
        else {
            is_used=false;
            tmp.push_back(c);
        }
    }
    new_id=tmp;
    tmp.clear();

    // step 4
    if (new_id.front()=='.') {
        new_id.erase(new_id.begin());
    }
    if (new_id.back()=='.') {
        new_id.erase(new_id.end()-1);
    }

    // step 5
    if (new_id.empty()) {
        new_id.push_back('a');
    }

    // step 6
    if (new_id.size()>15) { // >=16
        new_id.erase(new_id.begin()+15,new_id.end());
    }
    if (new_id.back()=='.') {
        new_id.erase(new_id.end()-1);
    }

    // step 7
    while (new_id.size()<3) {
        new_id.push_back(new_id.back());
    }

    return new_id;
}