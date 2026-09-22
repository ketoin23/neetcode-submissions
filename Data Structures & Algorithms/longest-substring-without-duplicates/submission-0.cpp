class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int res = 0;
        for(int i = 0, j = 0; j < s.size(); j++) {
            while(st.find(s[j]) != st.end()) {
                st.erase(s[i]);
                ++i;
            }

            st.insert(s[j]);
            res = max(res, (int)st.size());
        }

        return res;
    }
};
