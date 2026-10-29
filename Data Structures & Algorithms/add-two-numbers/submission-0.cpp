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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = l1;
        int carry = 0;

        while(l1 != nullptr && l2 != nullptr) {
            int sum = l1->val + l2->val + carry;
            l1->val = sum % 10;
            carry = sum / 10;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1 != nullptr) {
            int sum = l1->val + carry;
            l1->val = sum % 10;
            carry = sum / 10;
            l1 = l1->next;
        }

        l1 = res;
        while(l1->next != nullptr) {
            l1 = l1->next;
        }

        while(l2 != nullptr) {
            ListNode* nnode = new ListNode();
            l1->next = nnode;
            l1 = l1->next;
            int sum = l2->val + carry;
            l1->val = sum % 10;
            carry = sum / 10;
            l2 = l2->next;
        }

        if(carry) {
            ListNode* nnode = new ListNode();
            l1->next = nnode;
            l1 = nnode;
            l1->val = carry;
        }

        return res;
    }
};
