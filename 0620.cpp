class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head, *fast = head, *prev = nullptr;
        // �����ҵ������м�
        while (fast) {
            slow = slow->next;
            fast = fast->next ? fast->next->next : fast->next;
        }
        // ��ת��벿������
        while (slow) {
            ListNode* tmp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = tmp;
        }
        // �Ƚ���������
        while (head && prev) {
            if (head->val != prev->val)
                return false;
            prev = prev->next;
            head = head->next;
        }
        return true;
    }
};