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

    // take log's start point and end point
    vector<long long> total_time(360'000); // total_time[i] = i ~ i+1
    for (auto cur : log_sec) {
        ++total_time[cur.first];
        --total_time[cur.second];
    }

    // get interval ( 0 0 1 1 2 2 1 1 0 0 )
    for (int i = 1; i<play_time_sec; ++i) {
        total_time[i]+=total_time[i-1];
    }

    // get acc. interval ( 0 0 1 2 4 6 7 8 8 8 )
    for (int i = 1; i<play_time_sec; ++i) {
        total_time[i]+=total_time[i-1];
    }

    long long acc = total_time[adv_time_sec-1]; // 1~adv_time_sec
    int sec = 0;
    for (int i = adv_time_sec; i<play_time_sec; ++i) {
        if (acc<total_time[i]-total_time[i-adv_time_sec]) {
            acc=total_time[i]-total_time[i-adv_time_sec];
            sec=i-adv_time_sec+1;
        }
    }

    string answer = "";
    int hour = sec/3600;
    sec%=3600;
    if (hour<10) {
        answer.push_back('0');
    }
    answer+=to_string(hour);
    answer.push_back(':');
    int minute=sec/60;
    sec%=60;
    if (minute<10) {
        answer.push_back('0');
    }
    answer+=to_string(minute);
    answer.push_back(':');
    if (sec<10) {
        answer.push_back('0');
    }
    answer+=to_string(sec);

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