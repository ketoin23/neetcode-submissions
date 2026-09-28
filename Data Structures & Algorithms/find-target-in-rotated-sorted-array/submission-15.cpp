class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;

        while(l < r) {
            int m = (l + r) / 2;
            if(nums[m] >= nums[0]) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        int ll = 0, rr = l - 1;
        while(ll <= rr) {
            int m = (ll + rr) / 2;
            if(nums[m] == target)
                return m;
            if(nums[m] > target) {
                rr = m - 1;
            } else {
                ll = m + 1;
            }
        }

        ll = l; rr = n - 1;
        while(ll <= rr) {
            int m = (ll + rr) / 2;
            if(nums[m] == target)
                return m;
            if(nums[m] > target) {
                rr = m - 1;
            } else {
                ll = m + 1;
            }
        }

        return -1;
    }
};
