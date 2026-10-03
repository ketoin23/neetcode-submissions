class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int st = 0, en = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 1; i - j > -1 && i + j < n; j++) {
                if(s[i + j] == s[i - j]) {
                    if(2 * j + 1 > en - st + 1) {
                        st = i - j;
                        en = i + j;
                    }
                } else {
                    break;
                }
            }
        }

        for(int i = 1; i < n; i++) {
            for(int j = 0; i - 1 - j > -1 && i + j < n; j++) {
                if(s[i - j - 1] == s[i + j]) {
                    if(en - st + 1 < 2 * j + 2) {
                        st = i - j - 1;
                        en = i + j;
                    }
                } else {
                    break;
                }
            }
        }

        string res = s.substr(st, en - st + 1);
        return res;
    }
};
