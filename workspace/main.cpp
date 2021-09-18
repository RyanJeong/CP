#include <bits/stdc++.h>

using namespace std;

vector<int> get_fail(string);
vector<int> kmp(string, string);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    getline(cin,s);
    string p;
    getline(cin,p);

    auto res = kmp(s,p);
    cout << res.size() << '\n';
    for (auto i : res) {
        cout << i+1 << ' ';
    }

    return 0;
}

/*
    failure function
    두 문자열의 일치 여부 확인 중 불일치하다면, 
    이동할 다음 idx를 가리키는 함수
    (prefix와 postfix가 일치하는 길이)

  STRING : B A B A B A A
  i      : 0 1 2 3 4 5 6 
  fail(i): 0 0 1 2 3 4 0
  ----------------------
  i = 6(A), j = 4(B) -> 2
  i = 6(A), j = 2(B) -> 0
  i = 6(A), j = 0(B) => 0
*/
vector<int> get_fail(string p)
{
    int n_p = p.size();
    vector<int> fail(n_p);
    for (int i = 1, j = 0; i<n_p; i++) {
        while (j>0 && p[i]!=p[j]) {
            j=fail[j-1]; // restore the idx
        }
        if (p[i]==p[j]) {
            fail[i]=j+1; // after j
            ++j;
        }
    }

    return fail;
}

vector<int> kmp(string s, string p)
{
    auto fail = get_fail(p);
    int n_s = (int)s.size();
    int n_p = (int)p.size();

    vector<int> ans;
    for (int i = 0, j = 0; i<n_s; i++) {
        while (j>0 && s[i]!=p[j]) {
            j=fail[j-1];
        }
        if (s[i]==p[j]) {
            if (j==n_p-1){
                ans.push_back(i-n_p+1);
/*
    ABC    => j = 0
    ABCABC => j = 3
*/
                j=fail[j];
            }
            else {
                j++;
            }
        }
    }

    return ans;
}