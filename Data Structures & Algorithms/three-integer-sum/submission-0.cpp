class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1, k = n - 1; j < k;) {
                if(nums[i] + nums[j] + nums[k] == 0) {
                    res.push_back({nums[i], nums[j], nums[k]});
                    int f = nums[j], s = nums[k];
                    while(j < k && f == nums[j])
                        ++j;
                    while(j < k && s == nums[k])
                        --k;
                } else if(nums[i] + nums[j] + nums[k] < 0) {
                    ++j;
                } else {
                    --k;
                }
            }

            int f = nums[i];
            while(i < n && f == nums[i])
                ++i;
            --i;
        }

        return res;
    }
};
