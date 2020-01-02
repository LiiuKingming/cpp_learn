class Solution {
public:
    bool Find(int target, vector<vector<int>> array) {
        //首先判断数组是否为空
        if(array.empty()){
            return false;
        } else {
            //取首行
            int row = 0;
            //取最后一列
            int col = array[0].size() - 1;
            //边界
            while(row < array.size() && col >= 0){
                if(array[row][col] == target){
                    return true;
                    break;
                } else if(array[row][col] > target){
                    --col;
                } else {
                    ++row;
                }
            }
        }
        return false;
    }
};