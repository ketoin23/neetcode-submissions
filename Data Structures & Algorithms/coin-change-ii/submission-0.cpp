class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        
        for(auto c : coins) {
            vector<int> temp = dp;
            for(int i = 0; i < amount; i++) {
                if(dp[i]) {
                    int cur = i;
                    while(cur + c <= amount) {
                        temp[cur + c] += dp[i];
                        cur += c;
                    }
                }
            }
            dp = temp;
        }

        return dp[amount];
    }
};
