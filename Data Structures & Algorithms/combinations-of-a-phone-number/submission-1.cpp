class Solution {
    void f(int ind, string &s, string &cur, vector<string> &res, unordered_map<char, vector<char>> &mp) {
        if (ind == s.size()) {
            res.push_back(cur);
            return;
        }

        for(auto i : mp[s[ind]]) {
            cur += i;
            f(ind + 1, s, cur, res, mp);
            cur.pop_back();
        }
    }

    unordered_map<char, vector<char>> get() {
        char c = 'a';
        unordered_map<char, vector<char>> mp;
        for(char i = '2'; i <= '9'; i++) {
            for(int j = 0; j < 3; j++) {
                mp[i].push_back(c);
                ++c;
            }

            if(i == '7' || i == '9') {
                mp[i].push_back(c);
                ++c;
            }
        }

        return mp;
    }

public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
            return {};
        string cur = "";
        vector<string> res;
        unordered_map<char, vector<char>> mp = get();
        f(0, digits, cur, res, mp);

        return res;
    }
};
