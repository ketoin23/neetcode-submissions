class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto i : nums) {
            sum += i;
        }

        if(sum & 1)
            return false;

        sum /= 2;
        
        vector<bool>dp(sum + 1, false);
        dp[0] = true;
        for(int i = 0; i < nums.size(); i++) {
            vector<bool> temp = dp;
            for(int j = 0; j <= sum; j++) {
                if(j - nums[i] >= 0) {
                    if(dp[j - nums[i]])
                        temp[j] = true;
                }
            }
            dp = temp;
        }

        return dp[sum];
    }
};
