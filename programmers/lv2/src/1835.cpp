#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<string> data) 
{
    string buf = "ACFJMNRT";
    int answer = 0;
    do {
        bool is_right = true;
        for (string d : data) {
            int s = buf.find(d[0]);
            int t = buf.find(d[2]);
            int diff = abs(s-t)-1; // A~C=0 => 'A''C' = 0, 'A''F''C' = 1
            char op = d[3];
            int n = d[4]-'0';
            if (op=='=') {
                if (diff==n) {
                    continue;
                }
            }
            else if (op=='>') {
                if (diff>n) {
                    continue;
                }
            }
            else if (op=='<') {
                if (diff<n) {
                    continue;
                }
            }
            is_right=false;
            break;
        }    
        if (is_right) {
            ++answer;
        }
    } while (next_permutation(buf.begin(),buf.end()));


    return answer;
}