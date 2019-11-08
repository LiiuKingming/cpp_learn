//
// Created by 28943 on 2019/10/30.
//

#include "1030myString.h"

int main(){
    String s(4, 'n');
    String s2("bite");
    String s3 = s2;
    String s4("qiaobiluo");

    cout << s4 + s2 <<endl;
    cout << s4 + "fff" <<endl;
    cout << "fff" + s4  <<endl;
//    cout << s << endl;
//    cout << s2 << endl;
//    cout << s3 << endl;
//    cout << s4 << endl;

//    cout << s4.Size() << endl;
//    cout << s4.Capacity() << endl;
//    s4.Resize(16, '6');
//    cout << s4 << endl;
//    cout << s4.Size() << endl;
//    cout << s4.Capacity() << endl;
    return 0;
}
