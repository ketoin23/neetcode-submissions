class Solution {
    void f(int ind, vector<int> &v, vector<int> &cur, vector<vector<int>> &res) {
        if(ind == v.size()) {
            res.push_back(cur);
            return;
        }

        f(ind + 1, v, cur, res);
        cur.push_back(v[ind]);
        f(ind + 1, v, cur, res);
        cur.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> res;

        f(0, nums, cur, res);

        return res;
    }
};
