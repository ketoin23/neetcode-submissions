class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        vector<vector<int>> dp1(n, vector<int>(2, 0)); // takes first
        vector<vector<int>> dp2 = dp1; // skips first

        dp1[0][1] = nums[0];
        for(int i = 1; i < n - 1; i++) {
            dp1[i][0] = max(dp1[i - 1][1], dp1[i - 1][0]);
            dp1[i][1] = dp1[i - 1][0] + nums[i];
        }

        for(int i = 1; i < n; i++) {
            dp2[i][0] = max(dp2[i - 1][0], dp2[i - 1][1]);
            dp2[i][1] = dp2[i - 1][0] + nums[i];
        }

        return max({dp1[n - 2][0], dp1[n - 2][1], dp2[n - 1][0], dp2[n - 1][1]});
    }
};
