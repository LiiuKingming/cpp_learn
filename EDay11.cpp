//
// Created by 28943 on 2019/11/19.
//

#include <iostream>
using namespace std;

int main(){
    unsigned int n = 0;
    while(cin >> n) {
        int count = 0;
        int max = 0;
        for (int i = 31; i >= 0; i--) {
//        int tmp = (n >> i) & 1;
            if (((n >> i) & 1) == 1) {
                count++;
                if (count >= max)
                    max = count;
            } else if (((n >> i) & 1) == 0) {
                count = 0;
            }
        }
        cout << max << endl;
    }
    return 0;
}