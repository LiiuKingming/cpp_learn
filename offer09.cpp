class Solution {
public:
    /*
    bool g_InvalidInput = false;
    double Power(double base, int exponent) {
        g_InvalidInput = false;
        //???
        if(equal(base, 0.0) && exponent < 0){
            g_InvalidInput = true;
            return 0.0;
        }
         
        unsigned int absExponent = (unsigned int)(exponent);
        if(exponent < 0)
            absExponent = (unsigned int)(-exponent);
         
        double result = PowerRet(base, absExponent);
        if(exponent < 0)
            result = 1.0 / result;
        return result;
    }
     
    double PowerRet(double base, int exponent) {
        if(exponent == 0)
            return 1;
        if(exponent == 1)
            return base;
         
        double result = Power(base, exponent >> 1);
        result *= result;
        if(exponent & 0x1 == 1)
            result *= base;
         
        return result;
    }
    */
    double Power(double base, int exponent) {
        //强转long long防止abs(INT_MIN)溢出
        long long p = abs((long long) exponent);
        double result = 1.0;
        //右移相当于 / 2,同时效率更高
        for(; p; p >>= 1){
            if(p & 1)
                result *= base;
            base *= base;
        }
        //若指数为负数则返回倒数
        return exponent < 0 ? 1 / result : result;
    }
    
};