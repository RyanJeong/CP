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
int64_t PointInPolygon(const vector<pair<int, int>>& convex_hull,
                       const pair<int, int>&);

int main() {
  CP;

  int n, m, k;
  cin >> n >> m >> k;
  vector<pair<int, int>> v_a(n);
  for (auto& i : v_a)
    cin >> i.first >> i.second;
  // find the point with the lowest y-coordinate. (v[0], starting_point)
  sort(v_a.begin(), v_a.end(), CmpCoor);
  starting_point = v_a.front();
  // the set of points must be sorted in increasing order of the angle they and
  // the point P make with the x-axis
  sort(v_a.begin() + 1, v_a.end(), CmpCcw);

  // Graham's scan
  vector<pair<int, int>> convex_hull_a;
  for (const auto& p : v_a) {
    while (convex_hull_a.size() >= 2) {
      if (CalcCcw(
          convex_hull_a[convex_hull_a.size()-2], convex_hull_a.back(), p) > 0)
        break;
      convex_hull_a.pop_back();
    }
    convex_hull_a.push_back(p);
  }

  vector<pair<int, int>> v_b(m);
  for (auto& i : v_b)
    cin >> i.first >> i.second;
  sort(v_b.begin(), v_b.end(), CmpCoor);
  starting_point = v_b.front();
  sort(v_b.begin() + 1, v_b.end(), CmpCcw);
  vector<pair<int, int>> convex_hull_b;
  for (const auto& p : v_b) {
    while (convex_hull_b.size() >= 2) {
      if (CalcCcw(
          convex_hull_b[convex_hull_b.size()-2], convex_hull_b.back(), p) > 0)
        break;
      convex_hull_b.pop_back();
    }
    convex_hull_b.push_back(p);
  }

  // Determine if a point is inside a polygon
  int cnt = 0;
  while (k--) {
    static pair<int, int> p;
    cin >> p.first >> p.second;
    if (PointInPolygon(convex_hull_a, p) < 0 &&
        PointInPolygon(convex_hull_b, p) > 0)
      continue;
    ++cnt;
  }
  if (cnt)
    cout << cnt;
  else
    cout << "YES";

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

// ccw         : pos.
// on the line : 0
// cw          : neg.
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

// the value of return is positive: outside of the polygon
// the value of return is zero: lie on the line of the polygon
// the value of return is negative: inside of the polygon
int64_t PointInPolygon(const vector<pair<int, int>>& convex_hull,
                       const pair<int, int>& p) {
  // check right-side
  if (CalcCcw(convex_hull.front(), convex_hull[1], p) < 0)
    return 1;

  // check left-side
  if (CalcCcw(convex_hull.front(), convex_hull.back(), p) > 0)
    return 1;

  // find a section which contains the point:
  // direction: ccw
  // low: right-side
  // high: left-side
  // idx: 1, For the case where the point lies on the line(a vector from 0 to 1)
  int low = 1;
  int high = convex_hull.size();  // [low, high)
  int idx = 1;
  while (low < high) {
    int mid = (low + high) / 2;
    if (CalcCcw(convex_hull.front(), convex_hull[mid], p) > 0) {
      idx = mid;
      low = mid + 1;
    } else {
      high = mid;
    }
  }

  return CalcCcw(convex_hull[idx], p, convex_hull[idx+1]);
}
