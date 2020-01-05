/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        //注意是从尾到头,不能改变链表顺序,后遍历先输出,使用栈
        //或者递归,但是递归可能会导致栈溢出,的鲁棒性不好
        //if(head != nullptr){
            //if(head ->next != nullptr){
                //printListFromTailToHead(head->next);
            //}
            //cout << head->val << endl;
        //}
        stack<ListNode*> ns;
        vector<int> v;
        ListNode *node = head;
        while(node){
            //所有节点压栈
            ns.push(node);
            node = node->next;
        }
        
        while(!ns.empty()){
            node = ns.top();
            //若是直接打印则cout << node->val << endl;
            v.push_back(node->val);
            ns.pop();
        }
        
        return v;
    }
};