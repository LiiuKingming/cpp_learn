//
// Created by 28943 on 2019/11/20.
//
//2. 偶数素数和
#include <iostream>
using namespace std;


#if 0
bool Primenumber(int num){
    if (num == 1 || num == 2){
        return true;
    }
    for (int i = 2; i < num; i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int n = 0;

    while (cin >> n){
        int small = 0;
        int big = 0;
        if(n % 2 != 0){
            return 0;
        }
        for(int i = 1; i <= n / 2; i++){
            if (Primenumber(i) && Primenumber((n - i))){
                if (i > small){
                    small = i;
                    big = n - i;
                }
            }
        }
        cout << small << '\n' << big << endl;
    }
    return 0;
}
#else

int binInsert(int n, int m, int j, int i) {
    // write code here
}

int main(){
    int n = 0;
    int m = 0;
    int j = 0;
    int i = 0;
    while (cin >> n >> m >> j >> i) {
        binInsert(n, m, i, j);
    }

    return 0;
}

#endif