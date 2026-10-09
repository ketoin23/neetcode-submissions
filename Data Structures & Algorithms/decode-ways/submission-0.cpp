class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++) {
            // first standalone
            if(s[i - 1] == '0') {
                dp[i][0] = 0;
            } else {
                dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
            }

            //combined
            if(i == 1)
                continue;
            if(s[i - 2] == '0' || s[i - 2] > '2' || (s[i - 2] == '2' && s[i - 1] > '6')) {
                dp[i][1] = 0;
            } else {
                dp[i][1] = dp[i - 2][0] + dp[i - 2][1];
            }
        }

        return dp[n][0] + dp[n][1];
    }
};
