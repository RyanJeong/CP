#include <string>
#include <vector>

using namespace std;

int solution(string s) 
{
    int answer = 0;
    auto it = s.begin();
    while (it!=s.end()) {
        char c = *it;
        if (isdigit(c)) {
            answer=answer*10+c-'0';
            ++it;
        }
        else {
            answer*=10;
            if (c=='z') { // zero
                it+=4;
            }
            else if (c=='o') { // one
                it+=3;
                answer+=1;
            }
            else if (c=='t') { // two three
                if (*(it+1)=='w') { // two
                    it+=3;
                    answer+=2; 
                }
                else { // three
                    it+=5;
                    answer+=3; 
                }
            }
            else if (c=='f') { // four five
                if (*(it+1)=='o') {
                    it+=4;
                    answer+=4;
                }
                else {
                    it+=4;
                    answer+=5;
                }
            }
            else if (c=='s') { // six seven
                if (*(it+1)=='i') {
                    it+=3;
                    answer+=6;
                }
                else {
                    it+=5;
                    answer+=7;
                }
            }
            else if (c=='e') { // eight
                it+=5;
                answer+=8;
            }
            else if (c=='n') { // nine
                it+=4;
                answer+=9;
            }
        }
    }

    return answer;
}