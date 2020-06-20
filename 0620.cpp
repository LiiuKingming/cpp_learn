class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head, *fast = head, *prev = nullptr;
        // 首先找到链表中间
        while (fast) {
            slow = slow->next;
            fast = fast->next ? fast->next->next : fast->next;
        }
        // 反转后半部分链表
        while (slow) {
            ListNode* tmp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = tmp;
        }
        // 比较两端链表
        while (head && prev) {
            if (head->val != prev->val)
                return false;
            prev = prev->next;
            head = head->next;
        }
        return true;
    }
};