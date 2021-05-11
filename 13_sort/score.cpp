// http://icpc.me/10825
#include <bits/stdc++.h>

using namespace std;

typedef struct {
  string name;
  int    kor;
  int    eng;
  int    math;
} Student;

bool cmp(Student, Student);

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;

  cin >> n;
  vector<Student> v;

  for (int i = 0; i < n; ++i) {
    Student s;

    cin >> s.name >> s.kor >> s.eng >> s.math;
    v.push_back(s);
  }
  sort(v.begin(), v.end(), cmp);
  for (Student s : v) {
    cout << s.name << '\n';
  }

  return 0;
}

bool cmp(Student a, Student b) 
{
  if (a.kor > b.kor) {

    return true;
  } else if (a.kor == b.kor && a.eng < b.eng) {

    return true;
  } else if (a.kor == b.kor && a.eng == b.eng && a.math > b.math) {

    return true;
  } else if (a.kor == b.kor && a.eng == b.eng && a.math == b.math && a.name < b.name) {

    return true;
  } else {

    return false;
  }
}