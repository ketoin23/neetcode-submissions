class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n, 0), suf(n, 1);
        pref[0] = nums[0];
        suf[n - 1] = nums[n - 1];
        for(int i = 1; i < n - 1; i++) {
            pref[i] = pref[i - 1] * nums[i];
        }
        for(int i = n - 2; i > 0; i--) {
            suf[i] = suf[i + 1] * nums[i];
        }

        vector<int> res(n);
        res[0] = suf[1];
        res[n - 1] = pref[n - 2];

        for(int i = 1; i < n - 1; i++) {
            res[i] = pref[i - 1] * suf[i + 1];
        }

        return res;
    }
};
