class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while(l + 1 < r) {
            int x = (l + r) / 2;
            if(nums[x] == target)
                return x;
            
            if(nums[x] < target) {
                l = x;
            } else {
                r = x;
            }
        }

        if(nums[l] == target)
            return l;
        if(nums[r] == target)
            return r;
        return -1;
    }
};
