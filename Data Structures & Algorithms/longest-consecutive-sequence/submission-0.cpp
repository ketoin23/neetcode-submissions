class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(auto i : nums) {
            st.insert(i);
        }

        vector<int> v;
        for(auto i : st) {
            if(st.find(i - 1) == st.end()) {
                v.push_back(i);
            }
        }

        int res = 0;
        for(auto i : v) {
            int cnt = 1, cur = i;
            while(st.find(cur + 1) != st.end()) {
                ++cnt;
                ++cur;
            }

            res = max(res, cnt);
        }

        return res;
    }
};
