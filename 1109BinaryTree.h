//
// Created by 28943 on 2019/11/9.
//

#ifndef CPLUSPLUS_1109BINARYTREE_H
#define CPLUSPLUS_1109BINARYTREE_H


#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

namespace km {

    template<typename T>
    class TreeNode {
        T m_val;
        TreeNode<T> *m_left;
        TreeNode<T> *m_right;
    public:
        TreeNode(const T & val)
            :m_val(val){

        }
        //友元类模板用同一个T会产生冲突, 所以在声明的时候改成U
        template<class U>
        friend class Tree;
    };

    template<class T>
    class Tree {
        TreeNode<T> *m_root;

        static TreeNode<T> * maketree(const T *val, const T & end, int &i){
            //遇到结束符 跳过该位置
            if (val[i] == end){
                i++;
                return nullptr;
            }

            TreeNode<T> * root = new TreeNode<T>(val[i]);
            i++;

            root->m_left = maketree(val, end, i);
            root->m_right = maketree(val, end, i);

            return root;
        }
    public:
        Tree() :
                m_root(nullptr) {
        }

        Tree(const T *val, const T &end) {
            int i = 0;
            //参数 (根节点,) 值, 结束符号, 下标
            m_root = maketree(val, end, i);
        }

        //非递归遍历借助stack


        //前序遍历: 右孩子入栈-->进左孩子-->没有左孩子 去栈顶
//        vector<T> pre_order(){
        void pre_order(){
            TreeNode<T> * cur = m_root;
            stack<TreeNode<T> *> st;
//            vector<T> preOrder;
            while (cur){
//               preOrder.push_back(cur->m_val);
                cout << cur->m_val <<' ';
                if (cur->m_right){
                    st.push(cur->m_right);
                }
                if(cur->m_left){
                    cur = cur->m_left;
                } else {
                    if (st.empty()){
                        cur = nullptr;
                    } else {
                        cur = st.top();
                        st.pop();
                    }
                }
            }
//                return preOrder;
        }
        //中序遍历: 自己和左全入栈, 取栈顶, 打印栈顶, 右重复, 没右再取栈顶
        void in_order(){
            TreeNode<T> * cur = m_root;
            stack<TreeNode<T> *> st;

            while (cur || !st.empty()){
                for (; cur; cur = cur->m_left){
                    //cur与左孩子全部入栈
                    st.push(cur);
                }

                if(!st.empty()){//空了, 取栈顶
                    cur = st.top();
                    st.pop();
                    cout << cur->m_val << ' ';

                    cur = cur->m_right;
                }
            }
        }
        void post_order() {
            TreeNode<T> *cur = m_root;
            stack<TreeNode<T> *> st;
            stack<bool> tag;
            while (cur || !st.empty()){
                for (; cur; cur->m_left){
                    //每一个节点元素对应标签, 二者同步push, 同步pop
                    st.push(cur);
                    tag.push(false);
                }

                while (!st.empty() && tag.top()){
                    //tag.top()-->左子树访问标记被置位, 标记为true则该被打印
                    cur = st.top();
                    cout << cur->m_val <<' ';
                    st.pop();
                    tag.pop();

                    cur = nullptr;//最后出栈完毕将cur置空, 访问下一个节点或跳出循环
                }

                if(!st.empty()){
                    tag.top() = true;
                    cur = st.top();
                    cur = cur->m_right;
                }
            }
        }


        //两个节点最近公共祖先
        //方法1: 利用后序遍历根最后出栈的特点
        TreeNode<T> * lowestCommonAncestor_post(TreeNode<T> * p, TreeNode<T> * q){
            TreeNode<T> * cur = m_root;
            stack<TreeNode<T> *> st;
            stack<bool> tag;

            stack<TreeNode<T> *> res1;
            stack<TreeNode<T> *> res2;

            while (cur || !st.empty()){
                for (; cur; cur = cur->m_left){
                    st.push(cur);
                    tag.push(false);
                }

                while (!st.empty() && tag.top()){
                    cur = st.top();
                    if (cur == p || cur == q){
                        if (res1.empty()){
                            res1 = st;
                        } else {
                            res2 = st;
                        }
                    }
                    st.pop();
                    tag.pop();

                    cur = nullptr;
                }

                if (!st.empty()){
                    tag.top() = true;
                    cur = st.top();
                    cur = cur->m_right;
                }
            }

            if (res1.size() < res2.size()){
                //保持res1比较大
                swap(res1, res2);
            }

            int i = res1.size() - res2.size();

            for (;i > 0; i--)
            {
                res1.pop();
                //用这样的方式让两个栈长度对齐
            }

            while (res1.top() != res2.top()){
                //都出栈
                res1.pop();
                res2.pop();
            }
            //找到公共祖先
            return res1.top();
        }

        //方法2 中序遍历做法: 以我为根的子树内包含两个节点
        //当子树内找到两个数, 计数为2时就找到了
        TreeNode<T> * lowestCommonAncestor_in(TreeNode<T> * p, TreeNode<T> * q)
        {
            TreeNode<T> * cur = m_root;
            stack<TreeNode<T> *> st;
            TreeNode<T> * tmp = nullptr;
            size_t stsize = 0;

            while (cur || !st.empty()){
                for (; cur; cur = cur->m_left){
                    st.push(cur);
                }

                if (!st.empty()){
                    cur = st.top();

                    if (stsize > st.size()){//栈顶是parent,改指向重新置位
                        tmp = cur;
                        stsize = st.size();
                    }

                    if (cur == p || cur == q){//可能是祖先节点
                        if (!tmp){
                            tmp = cur;//保存这个点
                            stsize = st.size();//保存栈大小, 改变则改变指向
                        } else {
                            return tmp;
                        }
                    }
                    st.pop();
                    cur = cur->m_right;
                }
            }
            return nullptr;
        }
        void test(){
            TreeNode<T> * t = lowestCommonAncestor_in(m_root->m_right->m_left->m_right, m_root->m_right);
            cout << t->m_val;
        }

        //层序遍历:
        void level_orde(){
            queue<TreeNode<T> *> qu;
            TreeNode<T> * tmp;

            qu.push(m_root);
            while (!qu.empty()){//队列不为空
                tmp = qu.front();
                cout << tmp->m_val << ' ';
                qu.pop();

                //左右子树分别进队
                if(tmp->m_left){
                    qu.push(tmp->m_left);
                }
                if(tmp->m_right){
                    qu.push(tmp->m_right);
                }
            }
        }

        //层序遍历逐行打印
        void every_line_order(){
            queue<TreeNode<T> * > qu;
            TreeNode<T> * tmp;
            int length = 1;//记录每一行入队后队伍的长度,打印完一行换行即可
            //根第一行长度为1
            qu.push(m_root);

            while (!qu.empty()){
                for (int i = 0; i < length; i++){//每一行的长度打印
                    tmp = qu.front();
                    cout << tmp->m_val << " ";

                    //左右子树分别进队
                    if(tmp->m_left){
                        qu.push(tmp->m_left);
                    }
                    if(tmp->m_right){
                        qu.push(tmp->m_right);
                    }
                }
                cout << endl;
                length = qu.size();
            }
        }

        void max_level_order(){//每一行的最大值
            queue<TreeNode<T> *> qu;
            TreeNode<T> * tmp;
            int length = 1;
            T max;

            qu.push(m_root);
            while (!qu.empty()){
                max = qu.front()->val;//存储每一行最大值进行比较
                for(int i = 0; i < length; i++){
                    tmp = qu.front();

                    if (max < tmp->m_val){//大于存储最大值则进行交换
                        max = tmp->m_val;
                    }
                    qu.pop();

                    if (tmp->m_left){
                        qu.push(tmp->m_left);
                    }
                    if (tmp->m_right){
                        qu.push(tmp->m_right);
                    }
                }
                cout << max << ' ';
                length = qu.size();
            }
        }

    };
};
#endif //CPLUSPLUS_1109BINARYTREE_H
