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


int main() {
    int N = 0;
    cin >> N;
    vector<int> vec;
    for (int i = 0; i < N; ++i) {
        int num = 0;
        cin >> num;
        vec.push_back(num);
    }
    int n = vec.size();
    if (vec.size() == 1)
        cout << 0 << endl;
    else {
        if (vec[0] < vec[1]) {
            cout << 0 << endl;
        } else if(vec[n - 1] < vec[n - 2]){
            cout << n - 1 << endl;
        } else {
            int start = 0;
            int end = vec.size() - 1;
            while (start <= end) {
                int mid = (start + end) / 2;
                if (vec[mid] < vec[mid + 1] && vec[mid] < vec[mid - 1]) {
                    cout << mid << endl;
                    break;
                } else if (vec[mid - 1] < vec[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
        }
    }
    return 0;
}

int mainxx() {
    int n;
    while (cin >> n) {
        vector<vector<int>> curstmer;
        int s, t;
        for (int i = 0; i < n; ++i) {
            cin >> s >> t;
            curstmer.push_back({s, t});
        }
        sort(curstmer.begin(), curstmer.end(), [](vector<int>&a, vector<int>&b){
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });

        int start = curstmer[0][0];
        int end = curstmer[0][1];
        int count = 0;
        for (int i = 1; i < curstmer.size(); ++i) {
            if (curstmer[i][0] <= end) {
                ++count;
                if (end < curstmer[i][1]) {
                    end = curstmer[i][1];
                }
                if (start < curstmer[i][0]) {
                    start = curstmer[i][0];
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}

/*
        int start = 0, i = 0, ans = 0, stop = 0;
        while (i < curstmer.size()) {
            while (i < curstmer.size() && curstmer[i][0] <= start) {
                stop = max(stop, curstmer[i][1]);
                ++i;
            }
            ++ans;
            start = stop;
            if (i < curstmer.size() && curstmer[i][0] > start) {
                ans = -1;
                break;
            }

            if (stop > maxt) {
                break;
            }

        }
        if (ans == -1 || stop < maxt) {
            cout << -1 << endl;
        } else {
            cout << ans + 1<< endl;
        }
        */

#if 0
int N = 0; // 物品数
int M = 0; // 容量
//int w[] = {2, 2, 6, 5, 4};  // 物品的重量
//int v[] = {6, 3, 5, 4, 6};  // 物品的价值
vector<int> w; // 重量
vector<int> v; // 价值
vector<int> choose; // 已选择的物品
vector<int> maxv_w; // 最高价值装的东西
int maxv = 0; // 最高价值
int curw = 0; // 当前重量
int curv = 0; // 当前价值
int nodeal = 0; // 未处理的物品的价值

void func(int i) {
    if (i == N) {
        if (maxv < curv) {
            maxv = curv;
            maxv_w = choose;
        }
    } else {
        nodeal -= v[i];
        if (curw + w[i] <= M) {
            // 选择w[i]
            curw += w[i];
            curv += v[i];
            choose.push_back(w[i]);
            func(i + 1);

            // 放弃w[i]
            curw -= w[i];
            curv -= v[i];
            choose.pop_back();
        }

        if (curv + nodeal > maxv) {
            func (i + 1);
        }
        nodeal += v[i];
    }
}
int mainx() {
    while (cin >> N) {
        cin >> M;
        w.clear();
        v.clear();
        maxv_w.clear();
        choose.clear();
        curv = 0;
        curw = 0;
        maxv = 0;
        nodeal = 0;
        for (int i = 0; i < N; ++i) {
            int num;
            cin >> num;
            w.push_back(num);
        }
        for (int i = 0; i < N; ++i) {
            int num;
            cin >> num;
            v.push_back(num);
        }

        for (auto i : v) {
            nodeal += i;
        }
        func (0);

        for (auto ww : maxv_w) {
            cout << ww << ' ';
        }
        cout << endl;
        cout << "bestv:" << maxv << endl;
    }
    return 0;
}



int mai1n() {
    int n = 0, m = 0;
    while (cin >> n >> m) {
        for (int i = 1; i <= n; ++i) {
            if (i == m){
                cout << i << endl;
                continue;
            }
            int j = n - i;
            if (i + j == m){
                if (i < j)
                    cout << i << ' ' << j << endl;
                else
                    cout << j << ' ' << i << endl;
            }
        }
    }
    return 0;
}


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

int main4() {
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
#endif