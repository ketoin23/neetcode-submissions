class Solution {
    void f(int ind, vector<int> &v, vector<int> &cur, vector<vector<int>> &res, int target, int sum) {
        if(ind == v.size()) {
            if(sum == target) {
                res.push_back(cur);
            }

            return;
        }
        if(sum > target)
            return;

        f(ind + 1, v, cur, res, target, sum);
        cur.push_back(v[ind]);
        sum += v[ind];
        f(ind, v, cur, res, target, sum);
        cur.pop_back();
        sum -= v[ind];
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int sum = 0;
        vector<int> cur;
        vector<vector<int>> res;
        f(0, nums, cur, res, target, sum);

        return res;
    }
};
