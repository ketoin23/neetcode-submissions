class Solution {
    void f(int ind, string &cur, string &s, vector<string> &p, vector<vector<string>> &res) {
        if(ind == s.size()) {
            if(cur == "") {
                res.push_back(p);
            }

            return;
        }

        cur += s[ind];
        if(isPal(cur)) {
            p.push_back(cur);
            cur = "";
            f(ind + 1, cur, s, p, res);
            cur = p.back();
            p.pop_back();
        }

        f(ind + 1, cur, s, p, res);
    }

    bool isPal(string s) {
        for(int i = 0, j = s.size() - 1; i < j; i++, j--) {
            if(s[i] != s[j])
                return false;
        }

        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        string cur = "";
        vector<string> p;
        vector<vector<string>> res;
        f(0, cur, s, p, res);

        return res;
    }
};
