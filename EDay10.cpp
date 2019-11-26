//
// Created by 28943 on 2019/11/18.
//
#include <iostream>
#include <string>
using namespace std;
#if 0
//1. 井字棋判断胜利
class Board {
public:
    bool checkWon(vector<vector<int> > board) {
        // write code here
        if (board[0][0] == 1){
            if ((board[1][1] == 1 && board[2][2] == 1)
             || (board[1][0] == 1 && board[2][0] == 1)
             || (board[0][1] == 1 && board[0][2] == 1)){
                return true;
            }
        } else if (board[1][1] == 1){
            if ((board[0][1] == 1 && board[2][1] == 1)
             || (board[1][0] == 1 && board[1][2] == 1)
             || (board[0][2] == 1 && board[2][0] == 1)){
                return true;
            }
        } else if (board[2][2] == 1){
            if ((board[0][2] == 1 && board[1][2] == 1)
             || (board[2][0] == 1 && board[2][1] == 1)){
                return true;
            }
        }
        return false;
    }
};
#else
//密码评级
//void Rating(int ret){
//    if(ret >= 90){
//        cout << "VERY_SECURE";
//    } else if (ret >= 80){
//        cout << "SECURE";
//    }else if (ret >= 70){
//        cout << "VERY_STRONG";
//    }else if (ret >= 60){
//        cout << "STRONG";
//    }else if (ret >= 50){
//        cout << "AVERAGE";
//    }else if (ret >= 25){
//        cout << "WEAK";
//    }else if (ret >= 0){
//        cout << "VERY_WEAK";
//    }
//}
//
//int Password(string &password){
//    int score = 0, ret = 0;//加分, 得分
//    //长度
//    if(password.size() <= 4){
//        score = 4;
//    }else if(password.size() >= 5 && password.size() <= 7){
//        score = 10;
//    } else if(password.size() >= 8){
//        score = 25;
//    }
//    ret += score;
//
//    //字母
//    int big = 0, small = 0;
//    for (auto &i : password){
////        if ((!(i >= 'a' && i <= 'z')) && (!(i >= 'A' && i <= 'Z'))){
////            num = 0;
////        } else {
//        if (i >= 'a' && i <= 'z'){
//            small = 1;
//        }else if(i >= 'A' && i <= 'Z'){
//            big = 1;
//        }
//    }
//    if((small + big) == 1){
//        score = 10;
//    } else if((small + big) == 2) {
//        score = 20;
//    } else if((small + big) == 0){
//        score = 0;
//    }
//    ret += score;
//
//    //数字
//    int num = 0;
//    for (auto &i : password){
//        if(i >= '0' && i <= '9'){
//            num++;
//        }
//    }
//    if(num == 0){
//        score = 0;
//    } else if(num == 1){
//        score = 10;
//    } else if(num > 1){
//        score = 20;
//    }
//    ret += score;
//
//    //符号
//    int symbol = 0;
//    for (auto &i : password){
//        if((i >= 0x21 && i <= 0x2F)
//        || (i >= 0x3A && i <= 0x40)
//        || (i >= 0x5B && i <= 0x60)
//        || (i >= 0x7B && i <= 0x7E)){
//            symbol++;
//        }
//    }
//    if (symbol == 0){
//        score = 0;
//    }else if(symbol == 1){
//        score = 10;
//    } else if(symbol > 1){
//        score = 25;
//    }
//    ret += score;
//
//    //奖励
//    if ((small > 0 || big > 0) && num > 0 && symbol == 0){
//        ret += 2;
//    } else if ((small > 0 || big > 0) && num > 0 && symbol > 0){
//        ret += 3;
//    } else if(small > 0 && big > 0 && num > 0 && symbol > 0){
//        ret += 5;
//    }
//    return ret;
//}
//选择题 8
struct A{
    void foo(){printf("foo");}
    virtual void bar(){printf("bar");}
    A(){bar();}
};
struct B : A {
    void foo(){printf("b_foo");}
    void bar(){printf("b_bar");}
};
#endif
int main(){
    A *p = new B;
    p->foo();
    p->bar();
        return 0 ;
}
