#include <bits/stdc++.h>

using namespace std;

bool is_used[10];
set<set<string>> banned_ids;

bool is_banned_id(string id, string ban) 
{
    if (id.size()!=ban.size()) {

        return false;
    }

    for (int i = 0; i<id.size(); ++i) {
        if (ban[i]=='*') {
            continue;
        }
        if (id[i]!=ban[i]) {

            return false;
        }
    }

    return true;
}

void dfs(const vector<string>& user_id, 
         const vector<string>& banned_id, 
         int ban_cur, 
         set<string> subset)
{
    if (ban_cur==banned_id.size()) {
        banned_ids.insert(subset);

        return;
    }

    for (int i = 0; i<user_id.size(); ++i) {
        if (is_used[i]) {
            continue;
        }
        if (is_banned_id(user_id[i],banned_id[ban_cur])) {
            is_used[i]=true;
            set<string> sub(subset);
            sub.insert(user_id[i]);
            dfs(user_id,banned_id,ban_cur+1,sub);
            is_used[i]=false;
        }
    }
    
    return;
}

int solution(vector<string> user_id, vector<string> banned_id) 
{
    set<string> sub;

    dfs(user_id,banned_id,0,sub);

    return banned_ids.size();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cout << solution({"frodo", "fradi", "crodo", "abc123", "frodoc"},
                     {"fr*d*", "*rodo", "******", "******"}) << '\n';

    return 0;
}

