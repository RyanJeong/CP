#include <iostream>
/////
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) 
{
    int common_min = fees[0];
    int common_cost = fees[1];
    int over_min = fees[2];
    int over_cost = fees[3];
    int idx = 0;
    map<string, int> m;
    vector<int> buf;
    vector<int> total_time;

    for (auto record : records) {
        string time = record.substr(0,5);
        time.push_back(':');
        int time_min = 0;
        int tmp = 0;
        for (char c : time) {
            if (c==':') {
                time_min=time_min*60+tmp;
                tmp=0;
            }
            else {
                tmp=tmp*10+c-'0';
            }
        }

        string car_id = record.substr(6,4);
        if (m.find(car_id)==m.end()) {
            m[car_id]=idx++;
            buf.push_back(-1);
            total_time.push_back(0);
        }
        int car_idx=m[car_id];

        string state = record.substr(11,record.size());
        if (state=="IN") {
            buf[car_idx]=time_min;
        }
        else {
            total_time[car_idx]+=time_min-buf[car_idx];
            buf[car_idx]=-1;
        }
    }
    int out_time = 23*60+59;
    for (auto cur : m) {
        int idx = cur.second;
        if (buf[idx]>=0) {
            total_time[idx]+=out_time-buf[idx];
        }

    }

    vector<int> answer;
    for (auto cur : m) {
        int idx = cur.second;
        int cost = common_cost;
        if (total_time[idx]>common_min) {
            int tmp = total_time[idx]-common_min;
            cost+=(tmp/over_min)*over_cost;
            if (tmp%over_min) {
                cost+=over_cost;
            }
        }
        answer.push_back(cost);
    }

    return answer;
}
/////

int main(void)
{
    for (auto i : solution({180, 5000, 10, 600}, {"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"})) {
        cout << i << ' ';
    }
    cout << '\n';
    for (auto i : solution({1,461,1,10}, {"00:00 1234 IN"})) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}