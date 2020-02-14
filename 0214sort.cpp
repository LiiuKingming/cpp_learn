//
// Created by 28943 on 2020/1/29.
//
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

void Swap(int &a, int &b){
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void BubbleSort(vector<int> &v){
    int n = v.size();
    int cur, bound;

    for(bound = n; bound > 0; --bound){
        int flag = 0;

        for(cur = 1; cur < bound; ++cur){
            flag = 1;
            if(v[cur] < v[cur - 1]){
                Swap(v[cur], v[cur - 1]);
            }
        }

        if(flag == 0)
            break;
    }
}

int Dig(vector<int> &v, int start, int end){
    int a = start, b = end;
    int tmp = v[start];

    while(1){
        //后方找到一个小于基准值的数
        while(b > start && v[b] >= tmp){
            b--;
        }

        if(a < b){
            v[a] = v[b];
        } else {
            v[a] = tmp;
            return a;
        }

        //前方找到一个大于基准值的数
        while(a < end && v[a] <= tmp){
            a++;
        }

        if(a < b){
            v[b] = v[a];
        } else {
            v[b] = tmp;
            return b;
        }
    }
}

int Partition(vector<int> &a, int low, int high) {
    int x = a[high];// 将输入数组的最后一个数作为主元，用它来对数组进行划分
    int i = low - 1;// i是最后一个小于主元的数的下标
    for (int j = low; j < high - 1; j++) {// 遍历下标由low到high-1的数
        if (a[j] < x) {// 如果数小于主元的话就将i向前挪动一个位置，并且交换j和i所分别指向的数
            int temp;
            ++i;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    //经历上面的循环之后下标为从low到i(包括i)的数就均为小于x的数了,现在将主元和i+1位置上面的数进行交换
    a[high] = a[i + 1];
    a[i + 1] = x;
    return i + 1;
}


int Hoare(vector<int> &v, int start, int end){
    int a = start + 1, b = end - 2;
    int mid = (start + end) / 2;

    //取中
    if(v[start] > v[mid]){
        Swap(v[start], v[mid]);
    }
    if(v[mid] > v[end]){
        Swap(v[mid], v[end]);
    }
    if(v[start] > v[mid]){
        Swap(v[start], v[mid]);
    }

    if(end - start <= 2){
        return mid;
    }

    Swap(v[mid], v[end - 1]);

    while(a <= b){
        while(a < end - 1 && v[a] <= v[end - 1]){
            a++;
        }
        while(b > 1 && v[b] >= v[end - 1]){
            b--;
        }

        //相遇位置跳出
        if(a == b && (a == 1 || a == end - 1)){
            break;
        }

        if(a < b){
            Swap(v[a], v[b]);
        }
    }  
    Swap(v[a], v[end - 1]);
    return a;
}

void quickSort(vector<int> &v, int left, int right){
    if(left >= right){
        return;
    //} else if(right - left + 1 < 5){}
    } else {
        int mid = Partition(v, left, right);
        quickSort(v, left, mid - 1);
        quickSort(v, mid + 1, right);
    }
}

void quickSortNoR(vector<int> &v, int left, int right){
    stack<int> s;
    if(left < right){
        s.push(right);
        s.push(left);
    }

    while(!s.empty()){
        int begin = s.top();
        s.pop();
        int end = s.top();
        s.pop();
        int mid = Dig(v, begin, end);

        if(begin < mid - 1){
            s.push(mid - 1);
            s.push(begin);
        }
        if(mid + 1 < end){
            s.push(end);
            s.push(mid + 1);
        }
    }
}

void InsertSort(vector<int> &v){
    for(int i = 0; i < v.size() - 1; ++i){
        int end = i;
        int tmp = v[end + 1];

        while(end >= 0 && v[end] > tmp){
            v[end + 1] = v[end];
            --end;
        }
        v[end + 1] = tmp;
    }
}

void ShiftDown(vector<int> &v, int n, int root){
    int parent = root;
    int child = parent * 2 + 1;

    while(child < n){
        if(child + 1 < n && v[child + 1] > v[child]){
            child++;
        }

        if(v[child] > v[parent]){
            Swap(v[child], v[parent]);
            parent = child;
            child = parent * 2 + 1;
        } else {
            break;
        }
    }
}

void heapSort(vector<int> &v){
    int i, end;
    int n = v.size();
    for(i = (n - 2) / 2; i >= 0; --i){
        ShiftDown(v, n, i);
    }

    end = n - 1;
    while(end > 0){
        Swap(v[0], v[end]);
        ShiftDown(v, end, 0);
        --end;
    }
}


void MaxHeapDown(vector<int> &a, int start, int end) {
    int cur = start;
    int child = cur * 2 + 1;
    int tmp = a[cur];
    for(; child <= end; cur = child, child = child * 2 + 1) {
        if (child < end && a[child] < a[child + 1]) {
            ++child;
        }
        if (tmp >= a[child]) {
            break;
        } else {
            a[cur] = a[child];
            a[child] = tmp;
        }
    }
}

void HeapSort(vector<int> &a, int n) {
    int i, tmp;
    for(i = n / 2 - 1; i>= 0; --i) {
        MaxHeapDown(a, i, n - 1);
    }

    for(i = n - 1; i > 0; --i) {
        tmp = a[0];
        a[0] = a[i];
        a[i] = tmp;
        MaxHeapDown(a, 0, i - 1);
    }
}


int main(){
    vector<int> v = {8, 5, 6, 3, 10, 1, 9, 2, 4, 7};
    vector<int> v1 = {5, 2, 3, 1};
    int start = 0;
    int end = v.size() - 1;
    //quickSort(v, start, end);
    HeapSort(v1, v1.size());
    //quickSortNoR(v, start, end);
    //BubbleSort(v);
    //InsertSort(v);
    //HeapSort(v);
    for(auto &i : v1){
        cout << i <<' ';
    }

    return 0;
}
