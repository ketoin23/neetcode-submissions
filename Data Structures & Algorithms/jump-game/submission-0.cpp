class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0, mx = nums[0];
        while(i <= mx) {
            mx = max(mx, i + nums[i]);
            if(mx >= nums.size() - 1)
                return true;
            ++i;
        }

        return false;
    }
};
