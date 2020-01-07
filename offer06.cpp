class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.empty())
            return 0;
        int p1 = 0;
        int p2 = rotateArray.size() - 1;
        int pmid = p1;//初始化为p1应对旋转前后数组不变的情况
        while(rotateArray[p1] >= rotateArray[p2]){
            if(p2 - p1 == 1){
                pmid = p2;
                break;
            }

            pmid = (p1 + p2) / 2;
            
            //下标p1, p2, pmid的指向的数字相等的话, 只能顺序查找
            if(rotateArray[p1] == rotateArray[p2] && rotateArray[p1] == rotateArray[pmid])
                return minInOrder(rotateArray, p1, p2);
            
            //比大小移动指针下标
            if(rotateArray[pmid] >= rotateArray[p1])
                p1 = pmid;
            else if(rotateArray[pmid] <= rotateArray[p2])
                p2 = pmid;
        }
        return rotateArray[pmid];
    }
    //顺序查找
    int minInOrder(vector<int> &rotateArray, int p1, int p2){
        int ret = rotateArray[p1];
        for(int i = p1 + 1; i <= p2; i++){
            if(ret > rotateArray[i])
                ret = rotateArray[i];
        }
        return ret;
    }
};