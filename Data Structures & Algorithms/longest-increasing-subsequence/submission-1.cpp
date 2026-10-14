class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp;

        for(auto i : nums) {
            if(!dp.size() || dp.back() < i) {
                dp.push_back(i);
                continue;
            }

            int idx = lower_bound(dp.begin(), dp.end(), i) - dp.begin();
            dp[idx] = i;
        }

        return dp.size();
    }
};
