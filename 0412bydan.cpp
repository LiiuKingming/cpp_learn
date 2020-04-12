#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <memory>
#include <stack>
using namespace std;

int main3() {
    int n = 0, m = 0;
    while (cin >> n >> m) {
        vector<int> sale;
        vector<int> value;
        for (int i = 0; i < n; ++i) {
            int num = 0;
            cin >> num;
            sale.push_back(num);
        }
        for (int i = 0; i < m; ++i) {
            int num = 0;
            cin >> num;
            value.push_back(num);
        }

        int sum = 0;
        int maxsale = 0;
        int minsale = INT_MAX;
        // 最小优惠券
        for (int i = 0; i < n; ++i) {
            minsale = min(maxsale, sale[i]);
        }
        for (int i = 0; i < m; ++i) {
            // 物品价格小于最小优惠券不需要遍历
            if (value[i] < minsale) {
                sum += value[i];
                continue;
            } else if (value[i] == minsale){
                continue;
            }

            for (int j = 0; j < n; ++j) {
                if (value[i] >= sale[j]) {
                    maxsale = max(maxsale, sale[j]);
                }
            }
            sum += value[i] - maxsale;
        }
        cout << sum << endl;
    }
    return 0;
}

int main2() {
    int n = 0;
    while (cin >> n) {
        vector<int> vec;
        for (int i = 0; i < n; ++i) {
            int num = 0;
            cin >> num;
            vec.push_back(num);
        }
        cout << 1 << endl;

        for (int i = 1; i < vec.size(); ++i) {
            if (vec[i] < vec[i - 1]) {

            }
        }
    }
    return 0;
}



/*
2
6
3 7 1 4 1 2
3 7 3 6 3 2
5
1 1 1 1 1
1 2 1 3 1
 */

bool helper(vector<int>&a, vector<int>& b) {
    int diff = 0;
    bool flag = false;
    int i = 0;
    while (i < a.size()) {
        if (a[i] == b[i]) {
            ++i;
        } else {
            if (flag)
                return false;

            while (a[i] != b[i]) {
                if (diff == 0) {
                    diff = abs(a[i] - b[i]);
                    ++i;
                } else {
                    if (diff == abs(a[i] - b[i])) {
                        ++i;
                        continue;
                    } else {
                        return false;
                    }
                }
            }
            flag = true;
        }
    }
    return true;
}

int main1() {
    int t;
    cin >> t;
    while (t--) {
        int n = 0;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int num = 0;
            cin >> num;
            a.push_back(num);
        }
        vector<int> b;
        for (int i = 0; i < n; ++i) {
            int num = 0;
            cin >> num;
            b.push_back(num);
        }

        if (helper(a, b)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
/*

3
4
1 4 3 3
5
8 2 2 4 6
6
5 8 1 3 2 9


0 3 1 1
4 1 1 2 3
0 4 0 2 0 5

*/

int arr[100000];

int main() {
    int t = 0;
    cin >> t;
    while (t--) {
        int n = 0;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        //jie
        vector<int> leftsee(n);// 向左看到的楼
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            if (!s.empty() && arr[i] >= s.top())
                leftsee[i] = s.size();
            else
                leftsee[i] = 0;

            while (!s.empty() && s.top() < arr[i]) {
                s.pop();
            }
            s.push(arr[i]);
        }

        while (!s.empty()) {
            s.pop();
        }

        vector<int> rightsee(n);
        for (int i = n - 1; i >= 0; --i) {
            if (!s.empty() && arr[i] >= s.top())
                leftsee[i] = s.size();
            else
                leftsee[i] = 0;

            while (!s.empty() && s.top() <= arr[i]) {
                s.pop();
            }
            s.push(arr[i]);
        }

        for (int i = 0; i < n; ++i) {
            cout << leftsee[i] + rightsee[i] << ' ';
        }
    }
    return 0;
}

/*
int main() {
    int t = 0;
    cin >> t;
    while (t--) {
        int n = 0;
        cin >> n;
        vector<int> vec;
        for (int i = 0; i < n; ++i) {
            cin >> vec[i];
        }

        for (int i = 0, j = n - 1; i < n, j >= 0; ++i, --j) {
            a.push_back(s1.size());
            b.push_back(s2.size());

            while (!s1.empty() && s1.top() <= vec[i]) {
                s1.pop();
            }
            while (!s2.empty() && s2.top() <= vec[j]) {
                s2.pop();
            }
            s1.push(vec[i]);
            s2.push(vec[j]);
        }
        reverse(b.begin(), b.end());
        for (int i = 0; i < n; ++i) {
            cout << a[i] + b[i] + 1 << ' ';
        }
    }
    return 0;
}
 */