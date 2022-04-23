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
using std::make_pair;

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

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (auto& i : v)
      cin >> i.first >> i.second;
    sort(v.begin(), v.end(), CmpCoor);
    starting_point = v.front();
    sort(v.begin() + 1, v.end(), CmpCcw);
    vector<pair<int, int>> convex_hull;
    for (const auto& p : v) {
      while (convex_hull.size() >= 2) {
        if (CalcCcw(
            convex_hull[convex_hull.size()-2], convex_hull.back(), p) > 0)
          break;
        convex_hull.pop_back();
      }
      convex_hull.push_back(p);
    }

    int min_x = -30;
    int max_x = 30;
    int min_y = -30;
    int max_y = 30;
    vector<pair<int, pair<int, int>>> res;
    res.reserve((max_x - min_x - 1) * (max_y - min_y - 1));
    for (int y = max_y - 1; y > min_y; --y) {
      vector<int> temp;
      temp.reserve(max_x - min_x - 1);
      for (int x = min_x + 1; x < max_x; ++x) {
        if (PointInPolygon(convex_hull, {x, y}) < 0) {
          temp.push_back(x);
        }
      }
      if (!temp.empty())
        res.push_back({y, make_pair(temp.front(), temp.back())});
    }
    cout << res.size() << '\n';
    if (res.size()) {
      for (const auto& i : res) {
        cout << i.first << ' '
            << i.second.first << ' '
            << i.second.second << '\n';
      }
    }
cout << PointInPolygon(convex_hull, {1, 2}) << '\n';
cout << PointInPolygon(convex_hull, {2, 2}) << '\n';
cout << PointInPolygon(convex_hull, {2, 1}) << '\n';
cout << PointInPolygon(convex_hull, {3, 3}) << '\n';
  }

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
  int low = 0;
  int high = convex_hull.size();
  int idx = 0;
  while (low < high) {
    int mid = (low + high) / 2;
    if (CalcCcw(convex_hull.front(), convex_hull[mid], p) > 0) {
      idx = mid;
      low = mid + 1;
    } else if (CalcCcw(convex_hull.front(), convex_hull[mid], p) < 0) {
      high = mid;
    } else {
      idx = mid;
      break;
    }
    // if (CalcCcw(convex_hull.front(), convex_hull[mid], p) > 0) {
    //   idx = mid;
    //   low = mid + 1;
    // } else {
    //   high = mid;
    // }
  }
cout << "idx: " << idx << '\n';

  return CalcCcw(
      convex_hull[idx], p, convex_hull[(idx + 1)%convex_hull.size()]);
}
