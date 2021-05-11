#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

map<ll, ll> room;

ll check(ll num) 
{ 
	if (!room[num]) { // is empty

    return num;
  } else {

		return room[num] = check(room[num]);
  }
}


vector<long long> solution(long long k, vector<long long> room_number) 
{
  vector<long long> answer;
	
  for (ll num = 0; num < room_number.size(); ++num) {
    ll temp = check(room_number[num]);

    answer.push_back(temp);
    room[temp] = temp + 1;
  }

	return answer;
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ll k{10};
  vector<ll> room_number = { 1, 3, 4, 1, 3, 1 };
  vector<ll> result{solution(k, room_number)};

  for (ll l : result) {
    cout << l << ' ';
  }

  return 0;
}
