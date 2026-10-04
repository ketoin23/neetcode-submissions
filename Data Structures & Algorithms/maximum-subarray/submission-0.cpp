class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = -10001, cur = 0;
        for(auto i : nums) {
            if(cur + i >= 0) {
                cur += i;
                res = max(res, cur);
            } else {
                cur = 0;
            }
        }

        int mx = res;
        for(auto i : nums) {
            mx = max(i, mx);
        }

        return mx;
    }
};
