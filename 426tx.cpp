#include <iostream>
#include <vector>
#include <limits.h>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
  int T = 0;
  cin >> T;
  while (T--) {
    int n = 0;
    while (cin >> n) {
      vector<vector<int>> A;
      for (int i = 0; i < n; ++i) {
        int x = 0;
        int y = 0;
        cin >> x >> y;
        A.push_back({x, y});

      }
      vector<vector<int>> B;
      for (int i = 0; i < n; ++i) {
        int x = 0;
        int y = 0;
        cin >> x >> y;
        B.push_back({x, y});
      }

      double ret = INT_MAX;
      for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < B.size(); ++j) {
          double tmp = sqrt(pow((A[i][0] - B[j][0]), 2) + pow((A[i][1] - B[j][1]), 2));
          if (tmp < ret) {
            ret = tmp;
          }
        }
      }
      printf("%.3lf\n", ret);
    }
  }

  return 0;
}


int getLevel(int x) {
  for (int n = 0; ; ++n) {
    if (x >= pow(2, n - 1) && x < pow(2, n)) {
      return n;
    }
  }
}

int getNode (int x, int k) {
  int level = getLevel(x);
  int diff = level - k;
  if (diff <= 0) {
    return -1;
  }
  int n = x;
  for (int i = 0; i < diff; ++i) {
    n = (n - 1 - 1) / 2 + 1;
  }
  return n;
}

int mainxx() {
  int Q;
  while (cin >> Q) {
    for (int i = 0; i < Q; ++i) {
      int x, k;
      cin >> x >> k;
      cout << getNode(x, k) << endl;
    }
  }
  return 0;
}

int main2() {
  int n = 0;
  cin >> n;
  while (cin >> n) {

    vector<vector<int>> A;
    for (int i = 0; i < n; ++i) {
      int x = 0;
      int y = 0;
      cin >> x >> y;
      A.push_back({x, y});

    }
    vector<vector<int>> B;
    for (int i = 0; i < n; ++i) {
      int x = 0;
      int y = 0;
      cin >> x >> y;
      B.push_back({x, y});
    }

  }
  return 0;
}