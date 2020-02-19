class Solution {
public:
    int Fibonacci(int n) {
    	if(n == 0)
            return 0;
        if(n == 1 || n == 2)
            return 1;
    	int fn = 0;
    	int fn1 = 1;
        int fn2 = 1;

        //转移方程 :F(i) = F(i - 1) + F(i - 2)
        for(int i = 3; i <= n; ++i){
            fn = fn1 + fn2;
            fn1 = fn2;
            fn2 = fn;
        }
        //返回值
        return fn;
    }
};