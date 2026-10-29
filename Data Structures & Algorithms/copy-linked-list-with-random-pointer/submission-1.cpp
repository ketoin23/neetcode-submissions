/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr)
            return nullptr;
        unordered_map<Node*, Node*> mp;
        Node* cur = head;
        Node* nhead = new Node(0);
        Node* cur2 = nhead;
        mp[cur] = cur2;
        mp[nullptr] = nullptr;

        while(cur != nullptr) {
            cur2->val = cur->val;

            if(mp.find(cur->next) == mp.end()) {
                Node* nnode = new Node(0);
                mp[cur->next] = nnode;
            }
            if(mp.find(cur->random) == mp.end()) {
                Node* nnode = new Node(0);
                mp[cur->random] = nnode;
            }

            cur2->next = mp[cur->next];
            cur2->random = mp[cur->random];

            cur = cur->next;
            cur2 = cur2->next;
        }

        return nhead;
    }
};
