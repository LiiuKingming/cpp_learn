class Solution {
public:
    int jumpFloorII(int number) {
        //2的n-1次方
        //1左移n位相当于2的n次方
        return 1 << (number - 1);
    }
};