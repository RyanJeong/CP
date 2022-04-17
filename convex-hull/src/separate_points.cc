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
using std::swap;

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
bool IsDisjoint(int, int, int, int);
bool IsIntersect(const pair<int, int>&, const pair<int, int>&,
                 const pair<int, int>&, const pair<int, int>&);

int main() {
  CP;

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v1(n);
    for (auto& i : v1)
      cin >> i.first >> i.second;
    vector<pair<int, int>> v2(m);
    for (auto& i : v2)
      cin >> i.first >> i.second;

    if (!n || !m) {
      cout << "YES\n";
      continue;
    }
    if (n < 3 && m < 3) {
      if (n == 1)
        v1[1] = v1.front();
      if (m == 1)
        v2[1] = v2.front();
      cout << (IsIntersect(v1[0], v1[1], v2[0], v2[1]) ? "NO\n" : "YES\n");
      continue;
    }

    sort(v1.begin(), v1.end(), CmpCoor);
    starting_point = v1.front();
    sort(v1.begin() + 1, v1.end(), CmpCcw);
    sort(v2.begin(), v2.end(), CmpCoor);
    starting_point = v2.front();
    sort(v2.begin() + 1, v2.end(), CmpCcw);
    vector<pair<int, int>> convex_hull1;
    for (const auto& p : v1) {
      while (convex_hull1.size() >= 2) {
        if (CalcCcw(
            convex_hull1[convex_hull1.size()-2], convex_hull1.back(), p) > 0)
          break;
        convex_hull1.pop_back();
      }
      convex_hull1.push_back(p);
    }
    vector<pair<int, int>> convex_hull2;
    for (const auto& p : v2) {
      while (convex_hull2.size() >= 2) {
        if (CalcCcw(
            convex_hull2[convex_hull2.size()-2], convex_hull2.back(), p) > 0)
          break;
        convex_hull2.pop_back();
      }
      convex_hull2.push_back(p);
    }

    bool is_separated = true;
    if (n > 2) {
      for (const auto& p : v2) {
        if (PointInPolygon(convex_hull1, p) <= 0) {
          is_separated = false;
          break;
        }
      }
    }
    if (m > 2 && is_separated) {
      for (const auto& p : v1) {
        if (PointInPolygon(convex_hull2, p) <= 0) {
          is_separated = false;
          break;
        }
      }
    }
    cout << ((is_separated) ? "YES\n" : "NO\n");
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

// check whether [a, b] and [c, d] are intersect
bool IsDisjoint(int a, int b, int c, int d) {
  if (a > b)
    swap(a, b);
  if (c > d)
    swap(c, b);

  return b < c || d < a;
}

bool IsIntersect(const pair<int, int>& a, const pair<int, int>& b,
                 const pair<int, int>& c, const pair<int, int>& d) {
  int64_t ab = CalcCcw(a, b, c) * CalcCcw(a, b, d);
  int64_t cd = CalcCcw(c, d, a) * CalcCcw(c, d, b);

  // point a, b, c, d are lie on the same line
  if (!ab && !cd) {
    return !IsDisjoint(a.first, b.first, c.first, d.first) &&
           !IsDisjoint(a.second, b.second, c.second, d.second);
  }

  return ab <= 0 && cd <= 0;
}
