class Solution {
public:
     int  NumberOf1(int n) {
         /*
         int count = 0;
         int flag = 1;
         for(int i = 31; i >= 0; i--){
             if((n >> i) & flag)
                 count++;
         }
         return count;
         */
         int count = 0;
         while(n){
             ++count;
             n = (n - 1) & n;
         }
         return count;
     }
};