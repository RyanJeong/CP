/*
  Copyright 2021 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
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
int64_t Ccw(const pair<int, int>&,
            const pair<int, int>&,
            const pair<int, int>&);
int64_t SqDist(const pair<int, int>&,
               const pair<int, int>&);

int main() {
  CP;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i)
      cin >> v[i].first >> v[i].second;

    // find the point with the lowest y-coordinate. (v[0], starting_point)
    sort(v.begin(), v.end(), CmpCoor);
    starting_point = v[0];
    // the set of points must be sorted in increasing order of the angle they
    // and the point P make with the x-axis
    sort(v.begin() + 1, v.end(), CmpCcw);

    // Graham's scan
    vector<pair<int, int>> convex_hull;
    for (const auto& p : v) {
      while (convex_hull.size() >= 2) {
        if (Ccw(convex_hull[convex_hull.size()-2], convex_hull.back(), p) > 0)
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

    int64_t res = SqDist(convex_hull[left_i], convex_hull[right_i]);
    pair<int, int> res_left_coor = convex_hull[left_i];
    pair<int, int> res_right_coor = convex_hull[right_i];
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

      if (Ccw(origin, left_vector, right_vector) > 0)
        left_i = (left_i + 1) % n_edge;
      else
        right_i = (right_i + 1) % n_edge;

      if (SqDist(convex_hull[left_i], convex_hull[right_i]) > res) {
        res = SqDist(convex_hull[left_i], convex_hull[right_i]);
        res_left_coor = convex_hull[left_i];
        res_right_coor = convex_hull[right_i];
      }
    }
    cout << res_left_coor.first << ' '
         << res_left_coor.second << ' '
         << res_right_coor.first << ' '
         << res_right_coor.second << '\n';
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
  int64_t res = Ccw(starting_point, s, t);

  if (res)
    return res > 0;  // ccw : true, cw : false

  // res = 0
  int64_t dist1 = SqDist(s, starting_point);
  int64_t dist2 = SqDist(t, starting_point);

  return dist1 < dist2;
}

/* ccw         : pos.
   on the line : 0
   cw          : neg. */
int64_t Ccw(const pair<int, int>& a,
            const pair<int, int>& b,
            const pair<int, int>& c) {
  int64_t u1 = b.first - a.first;
  int64_t v1 = b.second - a.second;
  int64_t u2 = c.first - b.first;
  int64_t v2 = c.second - b.second;

  return u1 * v2 - u2 * v1;
}

int64_t SqDist(const pair<int, int>& s,
               const pair<int, int>& t) {
  int64_t diff_x = s.first - t.first;
  int64_t diff_y = s.second - t.second;

  return diff_x * diff_x + diff_y * diff_y;
}
