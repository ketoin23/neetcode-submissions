class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(auto i : nums) {
            sum += i;
        }

        if(abs(target) > sum)
            return 0;

        int n = 2 * sum + 1;

        vector<int> dp(n, 0);
        dp[sum] = 1;
        target += sum;

        for(auto i : nums) {
            vector<int> ndp(n, 0);
            for(int j = 0; j < n; j++) {
                if(!dp[j])
                    continue;
                
                if(j + i < n) {
                    ndp[j + i] += dp[j];
                }
                if(j - i >= 0) {
                    ndp[j - i] += dp[j];
                }
            }
            dp = ndp;
        }

        return dp[target];
    }
};
