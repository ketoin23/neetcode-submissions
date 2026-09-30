class Solution {
    void f(int ind, vector<int> &v, vector<int> &cur, vector<vector<int>> &res, int target, int sum, int prev) {
        if(ind == v.size()) {
            if(sum == target) {
                res.push_back(cur);
            }
            return;
        }

        if(sum > target)
            return;
        
        if(prev == v[ind]) {
            f(ind + 1, v, cur, res, target, sum, prev);
            return;
        }

        f(ind + 1, v, cur, res, target, sum, v[ind]);
        cur.push_back(v[ind]);
        sum += v[ind];
        f(ind + 1, v, cur, res, target, sum, 0);
        cur.pop_back();
        sum -= v[ind];
        
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int sum = 0;
        vector<int> cur;
        vector<vector<int>> res;

        f(0, candidates, cur, res, target, sum, 0);
        return res;
    }
};
