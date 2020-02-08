//leetcode 581. 最短无序连续子数组
//
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        //从左到右扫描(或从右到左)找局部极大值(或局部极小值),若位置放置不正确,找到其应该存在的地方
        int start = -1, end = -2;
        int n = nums.size();
        
        int Min = nums[n - 1];
        int Max = nums[0];

        for(int i = 0, pos = 0; i < n; i++) {
            pos = n - 1 - i;
            //找出局部极大、极小值
            Max = max(Max, nums[i]);
            Min = min(Min, nums[pos]);
            //如果当前值小于局部极大值，用end记录该位置，找到该max的合适位置，
            if(nums[i] < Max)
                end = i;
            //如果当前值大于局部极小值，用star记录该位置，找到该star的合适位置
            if(nums[pos] > Min)
                start = pos;
        }
        return end - start + 1;
    }
};

//leetcode 150. 逆波兰表达式
//
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> tmp;
        int a, b;
        
        //将数字放入栈中, 提升vector效率
        for (auto &vsi : tokens){//vsi-->string
            
            //vsi[0] >= '0' && vsi[0] <= '9';
            //判断字符是不是数字
            if(isdigit(vsi[0]) || vsi.size() > 1){//正数或size() > 1是负数
                tmp.push(atoi(vsi.c_str()));
            }else{
                a = tmp.top();
                tmp.pop();
                b = tmp.top();
                    
                switch(vsi[0]){
                    case '+':
                        tmp.top() = b + a;
                        break;
                    case '-':
                        tmp.top() = b - a;
                        break;
                    case '*':
                        tmp.top() = b * a;
                        break;
                    case '/':
                        tmp.top() = b / a;
                        break;
                }
            }
        }
        return tmp.top();
    }
};