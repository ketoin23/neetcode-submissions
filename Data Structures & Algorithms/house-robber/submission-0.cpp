class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][1] = nums[0];
        dp[1][0] = dp[0][1];
        dp[1][1] = nums[1];

        for(int i = 2; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = nums[i] + dp[i - 1][0];
        }

        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};
