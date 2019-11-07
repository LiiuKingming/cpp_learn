//
// Created by 28943 on 2019/11/7.
//

#include <iostream>
#include <stack>

using namespace std;

//最小栈
class MinStack {
    stack<int> m_data;
    stack<int> m_min;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        m_data.push(x);
        if(m_min.empty() || m_min.top() > x){
            m_min.push(x);
        }
    }

    void pop() {
        if(m_data.top() == m_min.top()){
            m_min.pop();
        }
        m_data.pop();
    }

    int top() {
        return m_data.top();
    }

    int getMin() {
        return m_min.top();
    }
};
