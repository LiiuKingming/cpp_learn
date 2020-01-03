class Solution {
public:
    void replaceSpace(char *str,int length) {
        if(str == nullptr && length <= 0)
            return;
        
        int oldlength = 0;
        int blocknum = 0;
        
        for(int i = 0; str[i] != '\0'; i++){
            //遍历计算空格数和字符串实际长度
            oldlength++;
            if(str[i] == ' '){
                ++blocknum;
            }
        }
        
        int newlength = oldlength + blocknum * 2;
        //替换后的长度若大于容量则返回
        if(newlength > length)
            return;
        
        //定义两个指针
        int indexold = oldlength;
        int indexnew = newlength;
        while (indexold >= 0 && indexnew > indexold){
            if(str[indexold] == ' '){
                str[indexnew--] = '0';
                str[indexnew--] = '2';
                str[indexnew--] = '%';
            } else {
                str[indexnew--] = str[indexold];
            }
            --indexold;
        }
    }
};