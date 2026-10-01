class Solution {
    void f(int n, int open, int close, string &cur, vector<string> &res) {
        if(open == n && close == n) {
            res.push_back(cur);
            return;
        }
        if(!open) {
            cur += '(';
            f(n, open + 1, close, cur, res);
            cur.pop_back();
            return;
        }
        if(open == n) {
            cur += ')';
            f(n, open, close + 1, cur, res);
            cur.pop_back();
            return;
        }

        cur += '(';
        f(n, open + 1, close, cur, res);
        cur.pop_back();

        if(open > close) {
            cur += ')';
            f(n, open, close + 1, cur, res);
            cur.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string cur = "";
        vector<string> res;
        f(n, 0, 0, cur, res);

        return res;
    }
};
