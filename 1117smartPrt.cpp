//
// Created by 28943 on 2019/11/17.
//
#include <iostream>
#include <memory>
using namespace std;

template <class T>
class smart_ptr{
    T* m_ptr;
public:
//    smart_ptr(const smart_ptr & o) = delete;
//    smart_ptr &operator=(const smart_ptr & o) = delete;

    smart_ptr(T * ptr = nullptr)
        :m_ptr(ptr){

    }
    ~smart_ptr(){
        if(m_ptr){
            delete [] m_ptr;
            m_ptr = nullptr;
        }
    }

    T &operator*(){
        return *m_ptr;
    }
    T *operator->(){
        //对类sp取->, 则是对成员指针m_a执行->, 返回指针
        return m_ptr;
    }

    T &operator [](int i){
        return m_ptr[i];
    }
};

class Test{
public:
    int m_a;
};

int main_()
{

    smart_ptr<Test> sp(new Test);
    sp->m_a = 5;
    cout << sp->m_a;
//    smart_ptr<Test> sp2;
//拷贝构造导致析构重释放
    return 0;
}


