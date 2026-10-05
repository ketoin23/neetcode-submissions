class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> mp(26, 0);
        for(int i = 0; i < s.size(); i++) {
            mp[s[i] - 'a'] = i;
        }

        int i = 0;
        vector<int> res;
        while(i < s.size()) {
            int mx = i, cnt = 0;
            while(i <= mx) {
                ++cnt;
                mx = max(mx, mp[s[i] - 'a']);
                ++i;
            }

            res.push_back(cnt);
        }

        return res;
    }
};
