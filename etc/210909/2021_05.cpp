#include <iostream>
///////////////////
#include <string>
#include <vector>

using namespace std;

int time_to_int(string str)
{
    str.push_back(':');
    int tmp = 0;
    int sec = 0;
    for (char c : str) {
        if (isdigit(c)) {
            tmp=tmp*10+c-'0';
        }
        else { 
            sec=sec*60+tmp;  
            tmp=0;
        }    
    }

    return sec;
}

string solution(string play_time, string adv_time, vector<string> logs) 
{
    // preprocess 
    int play_time_sec = time_to_int(play_time);
    int adv_time_sec = time_to_int(adv_time);
    vector<pair<int, int>> log_sec;
    for (auto log : logs) {
        log_sec.push_back({time_to_int(log.substr(0,8)),time_to_int(log.substr(9,8))});
    }

    vector<int> total_time(360'000);
    for (auto cur : log_sec) {
        ++total_time[cur.first];
        --total_time[cur.second];
    }
    for (int i = 1; i<play_time_sec; ++i) {
        total_time[i]+=total_time[i-1];
    }



    string answer = "";
    return answer;
}
//////////////////

int main(void)
{
    cout << solution("02:03:55","00:14:15",{"01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30"}) << endl;
    cout << solution("99:59:59","25:00:00",{"69:59:59-89:59:59", "01:00:00-21:00:00", "79:59:59-99:59:59", "11:00:00-31:00:00"}) << endl;
    cout << solution("50:00:00","50:00:00",{"15:36:51-38:21:49", "10:14:18-15:36:51", "38:21:49-42:51:45"}) << endl;
    return 0;
}