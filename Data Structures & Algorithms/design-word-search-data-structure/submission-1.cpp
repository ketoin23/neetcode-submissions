class Node {
public:
    unordered_map<char, Node*> mp;
    bool leaf = false;
};
class WordDictionary {
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
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
        return universalSearch(0, word, cur);
    }

    bool universalSearch(int ind, string word, Node* cur) {
        if(ind == word.size()) {
            return cur->leaf;
        }
        if(word[ind] == '.') {
            bool res = false;
            for(char c = 'a'; c <= 'z'; c++) {
                if(cur->mp.find(c) != cur->mp.end())
                    res = (res | universalSearch(ind + 1, word, cur->mp[c]));
            }

            return res;
        } else {
            if(cur->mp.find(word[ind]) == cur->mp.end()) {
                return false;
            }

            return universalSearch(ind + 1, word, cur->mp[word[ind]]);
        }
    }
};
