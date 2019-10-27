//
// Created by 28943 on 2019/10/29.
//
#include <iostream>
using namespace std;

class HeapOnly{
    int m_a;
    HeapOnly():
        m_a(0){}
//    HeapOnly(const HeapOnly&);
public:
    static HeapOnly* CreatObject(){
        return new HeapOnly;
    }
};
/*HeapOnly* HeapOnly::CreatObject(){
    HeapOnly* ho = new HeapOnly;
    return ho;
}*/

int main(){
    HeapOnly* h1;
}
