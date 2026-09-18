class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size(), res = 0;
        for(int i = 0, j = n - 1; i < j; ) {
            int cur = min(heights[i], heights[j]) * (j - i);
            res = max(res, cur);
            if(heights[i] >= heights[j]) {
                --j;
            } else {
                ++i;
            }
        }

        return res;
    }
};
