class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, prev = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            res = max(res, prices[i] - prev);
            prev = min(prev, prices[i]);
        }

        return res;
    }
};
