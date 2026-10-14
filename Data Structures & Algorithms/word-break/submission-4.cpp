class Solution {

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for(int i = 1; i <= n; i++) {
            if(dp[i - 1]) {
                for(auto j : wordDict) {
                    string cur = s.substr(i - 1, j.size());
                    if(cur == j) {
                        dp[i + j.size() - 1] = true;
                    }
                }
            }
        }

        for(auto i : dp) {
            cout << i << " ";
        } 

        return dp[n];
    }
};
