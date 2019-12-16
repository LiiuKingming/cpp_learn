//
// Created by 28943 on 2019/12/11.
//
class Solution {
public:
    int Add(int num1, int num2) {
        while (num2 != 0) {
            int tmp = num1 ^num2;
            num2 = (num1 & num2) << 1;
            num1 = tmp;
        }
        return num1;
    }
};
#include <iostream>
#include <string>
#define ADD(x, y) ((x) + (y))
#define CMP(x, y) ((x) > (y))
int main()
{
    double a, b, c;
    while (std::cin >> a >> b >> c)
    {
//对两边进行求和与第三遍进行比较
        if (CMP(ADD(a, b), c) && CMP(ADD(b, c), a) && CMP(ADD(a, c), b)) {
            std::cout << "Yes" << std::endl;
        }else {
            std::cout << "No" << std::endl;
        }
    }
    return 0;
}

