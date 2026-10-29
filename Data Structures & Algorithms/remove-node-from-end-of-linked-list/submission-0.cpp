/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = 0;
        ListNode* cur = head;
        while(cur != nullptr) {
            ++sz;
            cur = cur->next;
        }
        if(sz == 1)
            return nullptr;

        n = sz - n + 1;
        cur = head;
        while(cur != nullptr) {
            --n;
            if(n <= 0) {
                if(cur->next != nullptr)
                    cur->val = (cur->next->val);
            }
            cur = cur->next;
        }

        cur = head;
        for(int i = 1; i < sz - 1; i++) {
            cur = cur->next;
        }

        cur->next = nullptr;
        return head;
    }
};
