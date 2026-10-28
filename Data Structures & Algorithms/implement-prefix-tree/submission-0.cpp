class Node {
public:
    unordered_map<char, Node*> mp;
    bool leaf = false;    
};

class PrefixTree {
    Node* root;
public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* cur = root;
        for(auto i : word) {
            if(cur->mp.find(i) == cur->mp.end()) {
                cur->mp[i] = new Node();
            }

            cur = cur->mp[i];
        }

        cur->leaf = true;
    }
    
    bool search(string word) {
        Node* cur = root;
        for(auto i : word) {
            if(cur->mp.find(i) == cur->mp.end()) {
                return false;
            }

            cur = cur->mp[i];
        }

        return cur->leaf;
    }
    
    bool startsWith(string prefix) {
        Node* cur = root;
        for(auto i : prefix) {
            if(cur->mp.find(i) == cur->mp.end()) {
                return false;
            }

            cur = cur->mp[i];
        }
        return true;
    }
};
