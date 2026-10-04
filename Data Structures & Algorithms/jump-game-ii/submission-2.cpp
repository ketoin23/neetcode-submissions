class Solution {
public:
    int jump(vector<int>& nums) {
        int i = 0, mx = nums[0], res = 0;
        while(i < nums.size() - 1) {
            int cur = mx;
            ++res;
            for(int j = i; j <= min((int)nums.size() - 1, mx); j++) {
                cur = max(cur, j + nums[j]);
            }

            i = mx;
            mx = cur;
        }

        return res;
    }
};
