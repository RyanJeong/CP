#include <bits/stdc++.h>

using namespace std;

bool is_used[10];
set<set<string>> banned_ids;

bool is_banned_id(string id, string ban) 
{
  int id_len  = id.size();
  int ban_len = ban.size();

  if (id_len != ban_len) {

    return false;
  }
  bool is_found = true;

  for (int i = 0; i < id_len; ++i) {
    if (ban[i] == '*') {
      continue;
    }
    if (id[i] != ban[i]) {
      is_found = false;
      break;      
    }
  }

  return is_found;
}

void dfs(const vector<string> &user_id, const vector<string> &banned_id, int ban_cur, set<string> subset)
{
  int id_len  = user_id.size();
  int ban_len = banned_id.size();

  if (ban_cur == ban_len) {
    banned_ids.insert(subset);

    return;
  }
  for (int i = 0; i < id_len; ++i) {
    if (is_used[i]) {
      continue;
    }
    if (is_banned_id(user_id[i], banned_id[ban_cur])) {
      is_used[i] = true;
      set<string> sub(subset);
      sub.insert(user_id[i]);
      dfs(user_id, banned_id, ban_cur + 1, sub);
      is_used[i] = false;
    }
  }
  
  return;
}

int solution(vector<string> user_id, vector<string> banned_id) {
  set<string> sub;

  dfs(user_id, banned_id, 0, sub);

  return banned_ids.size();
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  vector<string> user_id   = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
  vector<string> banned_id  ={"fr*d*", "abc1**"};
  cout << solution(user_id, banned_id) << '\n';
  cout << solution({ "frodo", "fradi", "crodo", "abc123", "frodoc" }, { "*rodo", "*rodo", "******" });

  return 0;
}