/*
5 2
10 1
2 2
5 2
8 1
9 1
*/
int main() {
    int n = 0, k = 0;
    while (cin >> n >> k) {
        vector<vector<int>> vec;
        for (int i = 0; i < n; ++i) {
            vector<int> tmp;
            for (int j = 0; j < 2; ++j) {
                int num = 0;
                cin >> num;
                tmp.push_back(num);
            }
            vec.push_back(tmp);
        }


        // 按价格低到高排个序
        sort(vec.begin(), vec.end(), [](vector<int>&a, vector<int>&b){
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });

        int ret = 0;

        int i = vec.size() - 1;
        for (; i >= 0; --i) {
            if (vec[i][1] == 2) {
                break;
            }
        }


//        cout << endl;
//        for (int i = 0; i < vec.size(); ++i){
//            for (int j = 0; j < vec[i].size(); ++j) {
//                cout << vec[i][j] << ' ';
//            }
//            cout << endl;
//        }

    }
    return 0;
}

//
//int main() {
//    int n = 0;
//    while (cin >> n) {
//        vector<unsigned long long> vec; // 接收数据
//        for (int i = 0; i < n; ++i) {
//            unsigned long long num = 0;
//            cin >> num;
//            vec.push_back(num);
//        }
//
//        vector<int> ret;
//        for (int i = 0; i < n; ++i) {
//            int flag = 0;
//            for (int j = 0; j < n; ++j) {
//                flag = 0;
//                unsigned long long tmp = 0;
//                tmp = vec[i] & vec[j];
//                if (tmp == 0) {
//                    flag = 1;
//                    ret.push_back(1);
//                    break;
//                }
//            }
//
//            if (flag == 0) {
//                ret.push_back(-1);
//            }
//        }
//        for (auto i : ret) {
//            cout << i << ' ';
//        }
//        cout << endl;
//    }
//    return 0;
//}
//

int mainasd() {
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

int mainxxxxx() {
    int n;
    while (cin >> n) {
        vector<vector<int>> curstmer;
        int s, t;
        for (int i = 0; i < n; ++i) {
            cin >> s >> t;
            curstmer.push_back({s, t});
        }
//        sort(curstmer.begin(), curstmer.end(), [](vector<int>&a, vector<int>&b){
//            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
//        });

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