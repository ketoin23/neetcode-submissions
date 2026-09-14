class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<vector<int>, vector<string>> mp;
        for(auto i : strs) {
            vector<int> cur(26, 0);
            for(auto j : i) {
                cur[j - 'a']++;
            }

            mp[cur].push_back(i);
        }

        for(auto i : mp) {
            vector<string> cur;
            for(auto j : i.second) {
                cur.push_back(j);
            }
            res.push_back(cur);
        }

        return res;
    }
};
