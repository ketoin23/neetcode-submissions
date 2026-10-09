class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int res = n;

        for(int i = 0; i < n; i++) {
            for(int j = 1; j + i < n && i - j >= 0; j++) {
                if(s[i + j] == s[i - j]) {
                    ++res;
                } else {
                    break;
                }
            }
        }

        for(int i = 1; i < n; i++) {
            if(s[i] != s[i - 1])
                continue;
            
            ++res;
            for(int j = 1; j + i < n && i - j - 1 >= 0; j++) {
                if(s[i + j] == s[i - j - 1]) {
                    ++res;
                } else {
                    break;
                }
            }
        }

        return res;
    }
};
