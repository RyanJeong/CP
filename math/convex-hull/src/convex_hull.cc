/*
  Copyright 2021 Ryan M. Jeong <ryan.m.jeong@hotmail.com>

  https://www.acmicpc.net/problem/9240
*/
#include <iostream>
#include <vector>
#include <utility>
#include <stack>
#include <algorithm>
#include <cmath>
#include <iomanip>

// iostream
using std::cin;
using std::cout;
using std::fixed;

// vector
using std::vector;

// utility
using std::pair;

// stack
using std::stack;

// algorithm
using std::sort;
using std::max;

// cmath
using std::sqrt;

// iomanip
using std::setprecision;

// CP
#define CP do { \
  std::ios::sync_with_stdio(false); \
  cin.tie(NULL); \
} while (0)

pair<int, int> starting_point;

bool cmp_coor(const pair<int, int>&,
              const pair<int, int>&);
bool cmp_ccw(const pair<int, int>&,
             const pair<int, int>&);
int64_t is_ccw(const pair<int, int>&,
               const pair<int, int>&,
               const pair<int, int>&);

int main() {
  CP;
  int n;
  cin >> n;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; ++i)
    cin >> v[i].first >> v[i].second;

  // find the point with the lowest y-coordinate. (v[0], starting_point)
  sort(v.begin(), v.end(), cmp_coor);
  starting_point = v[0];
  // the set of points must be sorted in increasing order of the angle they and
  // the point P make with the x-axis
  sort(v.begin() + 1, v.end(), cmp_ccw);

  // Graham's scan
  vector<pair<int, int>> convex_hull;
  for (const auto& p : v) {
    while (convex_hull.size() >= 2) {
      if (is_ccw(convex_hull[convex_hull.size()-2], convex_hull.back(), p) > 0)
        break;
      convex_hull.pop_back();
    }
    convex_hull.push_back(p);
  }
  cout << convex_hull.size();

  return 0;
}

bool cmp_coor(const pair<int, int>& s,
              const pair<int, int>& t) {
  if (s.second > t.second)
    return true;

  if (s.second == t.second && s.first > t.first)
    return true;

  return false;
}

bool cmp_ccw(const pair<int, int>& s,
             const pair<int, int>& t) {
  int64_t ccw = is_ccw(starting_point, s, t);

  if (ccw)
    return ccw > 0;  // ccw : true, cw : false

  // ccw = 0
  int64_t x1 = s.first - starting_point.first;
  int64_t y1 = s.second - starting_point.second;
  int64_t x2 = t.first - starting_point.first;
  int64_t y2 = t.second - starting_point.second;
  int64_t dist1 = x1 * x1 + y1 * y1;
  int64_t dist2 = x2 * x2 + y2 * y2;

  return dist1 < dist2;
}

/* ccw         : pos.
   on the line : 0
   cw          : neg. */
int64_t is_ccw(const pair<int, int>& a,
               const pair<int, int>& b,
               const pair<int, int>& c) {
  int64_t u1 = b.first - a.first;
  int64_t v1 = b.second - a.second;
  int64_t u2 = c.first - b.first;
  int64_t v2 = c.second - b.second;

  return u1 * v2 - u2 * v1;
}

