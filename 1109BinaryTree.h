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
        //��Ԫ��ģ����ͬһ��T�������ͻ, ������������ʱ��ĳ�U
        template<class U>
        friend class Tree;
    };

    template<class T>
    class Tree {
        TreeNode<T> *m_root;

        static TreeNode<T> * maketree(const T *val, const T & end, int &i){
            //���������� ������λ��
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
            //���� (���ڵ�,) ֵ, ��������, �±�
            m_root = maketree(val, end, i);
        }

        //�ǵݹ��������stack


        //ǰ�����: �Һ�����ջ-->������-->û������ ȥջ��
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
        //�������: �Լ�����ȫ��ջ, ȡջ��, ��ӡջ��, ���ظ�, û����ȡջ��
        void in_order(){
            TreeNode<T> * cur = m_root;
            stack<TreeNode<T> *> st;

            while (cur || !st.empty()){
                for (; cur; cur = cur->m_left){
                    //cur������ȫ����ջ
                    st.push(cur);
                }

                if(!st.empty()){//����, ȡջ��
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
                    //ÿһ���ڵ�Ԫ�ض�Ӧ��ǩ, ����ͬ��push, ͬ��pop
                    st.push(cur);
                    tag.push(false);
                }

                while (!st.empty() && tag.top()){
                    //tag.top()-->���������ʱ�Ǳ���λ, ���Ϊtrue��ñ���ӡ
                    cur = st.top();
                    cout << cur->m_val <<' ';
                    st.pop();
                    tag.pop();

                    cur = nullptr;//����ջ��Ͻ�cur�ÿ�, ������һ���ڵ������ѭ��
                }

                if(!st.empty()){
                    tag.top() = true;
                    cur = st.top();
                    cur = cur->m_right;
                }
            }
        }


        //�����ڵ������������
        //����1: ���ú������������ջ���ص�
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
                //����res1�Ƚϴ�
                swap(res1, res2);
            }

            int i = res1.size() - res2.size();

            for (;i > 0; i--)
            {
                res1.pop();
                //�������ķ�ʽ������ջ���ȶ���
            }

            while (res1.top() != res2.top()){
                //����ջ
                res1.pop();
                res2.pop();
            }
            //�ҵ���������
            return res1.top();
        }

        //����2 �����������: ����Ϊ���������ڰ��������ڵ�
        //���������ҵ�������, ����Ϊ2ʱ���ҵ���
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

                    if (stsize > st.size()){//ջ����parent,��ָ��������λ
                        tmp = cur;
                        stsize = st.size();
                    }

                    if (cur == p || cur == q){//���������Ƚڵ�
                        if (!tmp){
                            tmp = cur;//���������
                            stsize = st.size();//����ջ��С, �ı���ı�ָ��
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

        //�������:
        void level_orde(){
            queue<TreeNode<T> *> qu;
            TreeNode<T> * tmp;

            qu.push(m_root);
            while (!qu.empty()){//���в�Ϊ��
                tmp = qu.front();
                cout << tmp->m_val << ' ';
                qu.pop();

                //���������ֱ����
                if(tmp->m_left){
                    qu.push(tmp->m_left);
                }
                if(tmp->m_right){
                    qu.push(tmp->m_right);
                }
            }
        }

        //����������д�ӡ
        void every_line_order(){
            queue<TreeNode<T> * > qu;
            TreeNode<T> * tmp;
            int length = 1;//��¼ÿһ����Ӻ����ĳ���,��ӡ��һ�л��м���
            //����һ�г���Ϊ1
            qu.push(m_root);

            while (!qu.empty()){
                for (int i = 0; i < length; i++){//ÿһ�еĳ��ȴ�ӡ
                    tmp = qu.front();
                    cout << tmp->m_val << " ";

                    //���������ֱ����
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

        void max_level_order(){//ÿһ�е����ֵ
            queue<TreeNode<T> *> qu;
            TreeNode<T> * tmp;
            int length = 1;
            T max;

            qu.push(m_root);
            while (!qu.empty()){
                max = qu.front()->val;//�洢ÿһ�����ֵ���бȽ�
                for(int i = 0; i < length; i++){
                    tmp = qu.front();

                    if (max < tmp->m_val){//���ڴ洢���ֵ����н���
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
