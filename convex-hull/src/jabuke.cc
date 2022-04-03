/*
  Copyright 2022 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

// CP
#define CP do {                     \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(NULL);               \
} while (0)

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

// iostream
using std::cin;
using std::cout;
using std::fixed;

// vector
using std::vector;

// utility
using std::pair;

// algorithm
using std::sort;

pair<int, int> starting_point;

bool CmpCoor(const pair<int, int>&,
             const pair<int, int>&);
bool CmpCcw(const pair<int, int>&,
            const pair<int, int>&);
int64_t CalcCcw(const pair<int, int>&,
                const pair<int, int>&,
                const pair<int, int>&);
int64_t CalcSqDist(const pair<int, int>&,
                   const pair<int, int>&);
bool IsInside(const vector<pair<int, int>>&,
              const pair<int, int>&);

int main() {
  CP;

  int n = 3;
  vector<pair<int, int>> v(n);
  for (auto& i : v)
    cin >> i.first >> i.second;

  // find the point with the lowest y-coordinate. (v[0], starting_point)
  sort(v.begin(), v.end(), CmpCoor);
  starting_point = v.front();
  // the set of points must be sorted in increasing order of the angle they and
  // the point P make with the x-axis
  sort(v.begin() + 1, v.end(), CmpCcw);

  // Graham's scan
  vector<pair<int, int>> convex_hull;
  for (const auto& p : v) {
    while (convex_hull.size() >= 2) {
      if (CalcCcw(convex_hull[convex_hull.size()-2], convex_hull.back(), p) > 0)
        break;
      convex_hull.pop_back();
    }
    convex_hull.push_back(p);
  }

  int m;
  cin >> m;
  // Determine if a point is inside a shape
  int cnt = 0;
  while (m--) {
    static pair<int, int> p;
    cin >> p.first >> p.second;
    if (!IsInside(convex_hull, p))
      continue;
    ++cnt;
  }
  cout << fixed;
  cout.precision(1);
  cout << static_cast<double>(CalcCcw(
      convex_hull[0], convex_hull[1], convex_hull[2])) / 2 << '\n';
  cout << cnt;

  return 0;
}

bool CmpCoor(const pair<int, int>& s,
             const pair<int, int>& t) {
  if (s.second < t.second)
    return true;

  if (s.second == t.second && s.first < t.first)
    return true;

  return false;
}

bool CmpCcw(const pair<int, int>& s,
            const pair<int, int>& t) {
  int64_t res = CalcCcw(starting_point, s, t);

  if (res)
    return res > 0;  // ccw : true, cw : false

  // res = 0
  int64_t dist1 = CalcSqDist(s, starting_point);
  int64_t dist2 = CalcSqDist(t, starting_point);

  return dist1 < dist2;
}

/* ccw         : pos.
   on the line : 0
   cw          : neg. */
int64_t CalcCcw(const pair<int, int>& a,
                const pair<int, int>& b,
                const pair<int, int>& c) {
  int64_t u1 = b.first - a.first;
  int64_t v1 = b.second - a.second;
  int64_t u2 = c.first - a.first;
  int64_t v2 = c.second - a.second;

  return u1 * v2 - u2 * v1;
}

int64_t CalcSqDist(const pair<int, int>& s,
                   const pair<int, int>& t) {
  int64_t diff_x = s.first - t.first;
  int64_t diff_y = s.second - t.second;

  return diff_x * diff_x + diff_y * diff_y;
}

bool IsInside(const vector<pair<int, int>>& convex_hull,
              const pair<int, int>& p) {
  // check right-side
  if (CalcCcw(convex_hull.front(), convex_hull[1], p) < 0)
    return false;

  // check left-side
  if (CalcCcw(convex_hull.front(), convex_hull.back(), p) > 0)
    return false;

  // find a section which contains the point:
  // direction: ccw
  // low: right-side
  // high: left-side
  int low = 1;
  int high = convex_hull.size() - 1;
  while (low < high) {
    int mid = (low + high) / 2;
    if (CalcCcw(convex_hull.front(), convex_hull[mid], p) >= 0)
      low = mid + 1;
    else
      high = mid;
  }

  // result of ccw is positive: outside
  return CalcCcw(convex_hull[low-1], p, convex_hull[low]) <= 0;
}
