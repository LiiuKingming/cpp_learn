//
// Created by 28943 on 2019/12/7.
//

#ifndef CPLUSPLUS_AVLTREE_H
#define CPLUSPLUS_AVLTREE_H

#include <vector>
#include <stack>

namespace km{
    template <class T>
    class TreeNode{
        int m_bf;//记录平衡因子
        T m_data;
        TreeNode<T> * m_left;
        TreeNode<T> * m_right;
        TreeNode<T> * m_parent;
    public:
        TreeNode(const T &val = T()):
        m_bf(0),
        m_data(val),
        m_left(nullptr),
        m_right(nullptr),
        m_parent(nullptr){}

        template <class U>
        friend class AVLTree;
    };

    template <class T>
    class AVLTree{
        TreeNode<T> * m_root;

        void destory(TreeNode<T> *root){
            if(root){
                destory(root->m_left);
                destory(root->m_right);
                delete root;
            }
        }

        //节点平衡因子将从1变为2时可能会发生左旋
        void lRound(TreeNode<T> * pre){
            TreeNode<T> * parent = pre->m_parent;
            TreeNode<T> * cur = pre->m_right;

            cur->m_parent = parent;

            //执行左旋的节点如果有父节点, 则用左旋节点的右节点取代左旋节点
            //即将cur挂在pre原对应的parent左/右节点位置上
            if(parent){
                 if(parent->m_left = pre){
                    parent->m_left = cur;
                 } else {
                   parent->m_right = cur;
                 }
            } else {
                  m_root = cur;
            }

            // cur的左子树挂在pre的右子树上
            pre->m_right = cur->m_left;
            if(cur->m_left){
                cur->m_left->m_parent = pre;
            }
            //完成剩下的左旋操作
            cur->m_left = pre;
            pre->m_parent = cur;

            //旋转完成调整平衡因子
            cur->m_bf = pre->m_bf = 0;
        }

        void rRound(TreeNode<T> * pre){
            TreeNode<T> * parent = pre->m_parent;
            TreeNode<T> * cur = pre->m_left;

            cur->m_parent = parent;

            //执行右旋的节点如果有父节点, 则用右旋节点的左子树取代右旋节点
            //即将cur挂在pre原对应的parent左/右节点位置上
            if(parent){
                if(parent->m_left = pre){
                    parent->m_left = cur;
                } else {
                    parent->m_right = cur;
                }
            } else {
                m_root = cur;
            }

            // cur的左子树挂在pre的右子树上
            pre->m_left = cur->m_right;
            if(cur->m_right){
                cur->m_right->m_parent = pre;
            }
            //完成剩下的右旋操作
            cur->m_right = pre;
            pre->m_parent = cur;

            //旋转完成调整平衡因子
            cur->m_bf = pre->m_bf = 0;
        }

        void rlRound(TreeNode<T> * pre){
            TreeNode<T> * right = pre->m_right;
            TreeNode<T> * newroot = right->m_left;

            int flag = newroot->m_bf;

            rRound(pre->m_right);
            lRound(pre);

            if(flag == -1){
                right->m_bf = 1;
            } else if (flag == 1){
                pre->m_bf = -1;
            }
        }

        void lrRound(TreeNode<T> * pre){
            TreeNode<T> * left = pre->m_left;
            TreeNode<T> * newroot = left->m_right;

            int flag = newroot->m_bf;

            rRound(pre->m_left);
            lRound(pre);

            if(flag == -1){
                left->m_bf = 1;
            } else if (flag == 1){
                pre->m_bf = -1;
            }
        }

    public:
        AVLTree():
            m_root(nullptr){
        }

        ~AVLTree(){
            destory(m_root);
        }

        bool insert(const T &val){
            //1. 先按照二叉搜索树的规则将节点插入到AVL树中
            if(m_root == nullptr){
                m_root = new TreeNode<T>(val);
                return true;
            }

            TreeNode<T> *cur = m_root;
            TreeNode<T> * pre = nullptr;

            while (cur){
                if(val < cur->m_data){
                    pre = cur;
                    cur = cur->m_left;
                } else if(val > cur->m_data){
                    pre = cur;
                    cur = cur->m_right;
                } else {
                    return false;
                }
            }

            cur = new TreeNode<T>(val);
            if(val < pre->m_data){
                pre->m_left = cur;
            } else {
                pre->m_right = cur;
            }

            cur->m_parent = pre;

            // 2. 新节点插入后，AVL树的平衡性可能会遭到破坏，
            // 此时就需要更新平衡因子，并检测是否破坏了AVL树的平衡性
            while (pre){
                if (pre->m_left == cur){
                    pre->m_bf--;
                } else {
                    pre->m_bf++;
                }

                if(pre->m_bf == 0){
                    break;
                } else if(pre->m_bf == 1 || pre->m_bf == -1){
                    cur = pre;
                    pre = pre->m_parent;
                } else {
                    if (pre->m_bf == 2){
                        //pre的平衡因子为2, 则分为两种情况
                        if(cur->m_bf == 1){
                            //cur平衡因子为1则说明cur的右子树比左子树高1,此时左旋
                            lRound(pre);
                        } else {
                            //否则cur平衡因子为-1则说明cur的左子树比右子树高1,此时先左旋再右旋
                            rlRound(pre);
                        }
                    } else {
                        if(cur->m_bf == 1){
                            //cur平衡因子为1则说明cur的右子树比左子树高1,此时先左旋再右旋
                            lrRound(pre);
                        } else {
                            //否则cur平衡因子为-1则说明cur的左子树比右子树高1,此时右旋
                            rRound(pre);
                        }
                    }
                    break;
                }
            }
            return true;
        }

        bool erase(const T &val){
            if(m_root == nullptr){
                return false;
            }
            //先找到要删除的节点
            TreeNode<T> * cur = m_root;
            TreeNode<T> * pre = m_root;

            while (cur){
                if(val < cur->m_data){
                    pre = cur;
                    cur = cur->m_left;
                } else if (val > cur->m_data){
                    pre = cur;
                    cur = cur->m_right;
                } else {
                    break;
                }
            }

            if (cur == nullptr){
                return false;
            }

            //找到以后有三种情况
            if (cur->m_left && cur->m_right){//左右子树都有的时候有两种做法:

                TreeNode<T> * cur2 = cur->m_left;
                TreeNode<T> * pre2 = cur;

                if(cur2->m_right){ //左子树有右孩子
                    //则一路向右找到最后一个右子树
                    for(; cur2->m_right; pre2 = cur2, cur2 = cur2->m_right);
                    //最后的一个右孩子，将这个孩子的左子树挂在它父亲的右子树上
                    pre2->m_right = cur2->m_left;
                    cur2->m_left = cur->m_left;
                }

                cur2->m_right = cur->m_right;

                if(cur == pre){
                    m_root = cur2;
                } else {
                    if(cur->m_data < pre->m_data){
                        pre->m_left = cur2;
                    } else {
                        pre->m_right = cur2;
                    }
                }
                delete cur;
            } else if (cur->m_left){
                if(cur == pre){
                    m_root = cur->m_left;
                } else {
                    if (cur->m_data < pre->m_data){
                        pre->m_left = cur->m_left;
                    } else {
                        pre->m_right = cur->m_left;
                    }
                }
                delete cur;
            }
        }
        std::vector<T> InOrder(){
            std::stack<TreeNode<T> *> s;
            std::vector<T> res;
            TreeNode<T> * cur = m_root;

            while (cur || !s.empty()){
                for (; cur; cur = cur->m_left){
                    s.push(cur);
                }
                if (!s.empty()){
                    cur = s.top();
                    res.push_back(cur->m_data);
                    s.pop();

                    cur = cur->m_right;
                }
            }
            return res;
        }
    };
};



#endif //CPLUSPLUS_AVLTREE_H
