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
#include <cmath>

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

// cmath
using std::sqrt;

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
double CalcSqDistPointToVector(const pair<int, int>&,
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
  sort(v.begin(), v.end(), CmpCoor);
  starting_point = v.front();
  // the set of points must be sorted in increasing order of the angle they
  // and the point P make with the x-axis
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

  // Rotating calipers
  int left_i = 0;
  int right_i = 0;
  int n_edge = convex_hull.size();
  for (int i = 0; i < n_edge; ++i) {
    if (convex_hull[i].first < convex_hull[left_i].first)
      left_i = i;
    if (convex_hull[i].first > convex_hull[right_i].first)
      right_i = i;
  }

  double shortest_dist = static_cast<double>(
      CalcSqDist(convex_hull[left_i], convex_hull[right_i]));
  pair<int, int> origin = { 0, 0 };
  for (int i = 0; i < n_edge; ++i) {
    pair<int, int> left_vector = {
      convex_hull[(left_i + 1)%n_edge].first - convex_hull[left_i].first,
      convex_hull[(left_i + 1)%n_edge].second - convex_hull[left_i].second
    };
    pair<int, int> right_vector = {
      convex_hull[right_i].first - convex_hull[(right_i + 1)%n_edge].first,
      convex_hull[right_i].second - convex_hull[(right_i + 1)%n_edge].second
    };

    double dist = 0.0;
    if (CalcCcw(origin, left_vector, right_vector) > 0) {
      dist = CalcSqDistPointToVector(convex_hull[right_i],
                                     convex_hull[(left_i + 1)%n_edge],
                                     convex_hull[left_i]);
      left_i = (left_i + 1) % n_edge;
    } else {
      dist = CalcSqDistPointToVector(convex_hull[left_i],
                                     convex_hull[right_i],
                                     convex_hull[(right_i + 1)%n_edge]);
      right_i = (right_i + 1) % n_edge;
    }
    if (shortest_dist > dist)
      shortest_dist = dist;
  }
  cout << fixed;
  cout.precision(13);
  cout << sqrt(shortest_dist);

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

/*
  Distance(AH) point(A) to vector(u)
  |AH| = |AP x u| / |u|
  (point P is any point on vector u)
  ---------------------
  1. |AP x u| = |AP||u|sin(theta)
  2. |AH| = |AP|sin(theta)
  3. |AH||u| = |AP x u|
  => |AH| = |AP x u| / |u|
*/
double CalcSqDistPointToVector(const pair<int, int>& a,
                               const pair<int, int>& u1,
                               const pair<int, int>& u2) {
  pair<int64_t, int64_t> ap = { a.first - u1.first, a.second - u1.second };
  pair<int64_t, int64_t> u = { u1.first - u2.first, u1.second - u2.second };
  int64_t sq_apu =
      (ap.first * u.second - ap.second * u.first) *
      (ap.first * u.second - ap.second * u.first);
  int64_t sq_u = (u.first * u.first) + (u.second * u.second);

  return static_cast<double>(sq_apu) / static_cast<double>(sq_u);
}
