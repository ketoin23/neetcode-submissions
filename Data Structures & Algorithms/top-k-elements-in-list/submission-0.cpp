class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> f(2001, 0);
        for(auto i : nums) {
            f[i + 1000]++;
        }

        vector<vector<int>> ff(nums.size() + 1, vector<int>());
        for(int  i = 0; i < 2001; i++) {
            if(f[i])
                ff[f[i]].push_back(i - 1000);
        }

        vector<int> res;
        for(int i = nums.size(); i > -1 && k > 0; i--) {
            for(auto j : ff[i]) {
                res.push_back(j);
                --k;
            }
        }

        return res;
    }
};
