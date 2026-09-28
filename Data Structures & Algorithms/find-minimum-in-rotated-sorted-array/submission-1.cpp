class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while(l + 1 < r) {
            int m = (l + r) / 2;
            if(nums[m] > nums[0]) {
                l = m;
            } else {
                r = m;
            }
        }

        ++l;
        if(l == n)
            l = 0;
        
        return min(nums[0], nums[l]);
    }
};
