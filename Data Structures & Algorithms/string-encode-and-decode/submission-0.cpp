class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(auto i : strs) {
            int len = i.size();
            string l = to_string(len);
            res += l;
            res += "-";
            res += i;
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        cout << s;

        for(int i = 0; i < s.size(); i++) {
            string l = "";
            int j = i;
            while(s[j] != '-') {
                l += s[j];
                ++j;
            }
            ++j;

            int len = stoi(l);
            string cur = "";
            while(len--) {
                cur += s[j];
                ++j;
            }

            res.push_back(cur);
            i = j - 1;
        }

        return res;
    }
};
