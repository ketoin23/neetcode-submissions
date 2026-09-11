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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(list1 == nullptr)
            return list2;
        // merging all to list1

        ListNode *cur1 = list1, *cur2 = list2;
        while(cur1 != nullptr && cur2 != nullptr) {
            int val1 = cur1->val, val2 = cur2->val;
            if(val1 <= val2) {
                cur1 = cur1->next;
                continue;
            }

            cur1->val = val2;
            cur2->val = val1;
            ListNode* nxt1 = cur1->next;
            cur1->next = cur2;
            ListNode* nxt2 = cur2->next;
            cur2->next = nxt1;
            cur2 = nxt2;
        }

        if(cur2 != nullptr) {
            cur1 = list1;
            while(cur1->next != nullptr)
                cur1 = cur1->next;
            
            cur1->next = cur2;
        }

        return list1;
    }
};
