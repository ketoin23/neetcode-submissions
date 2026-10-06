/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr)
            return nullptr;

        Node* res = new Node(node->val);
        unordered_map<Node*, Node*> vis;
        queue<pair<Node*, Node*>> q;
        q.push({node, res});

        while(!q.empty()) {
            Node* cur = q.front().first;
            Node* curNew = q.front().second;
            q.pop();
            vis[cur] = curNew;

            for(auto i : cur->neighbors) {
                if(vis[i] == nullptr) {
                    Node* temp = new Node(i->val);
                    curNew->neighbors.push_back(temp);
                    vis[i] = temp;
                    q.push({i, temp});
                } else {
                    curNew->neighbors.push_back(vis[i]);
                }
            }
        }

        return res;
    }
};
