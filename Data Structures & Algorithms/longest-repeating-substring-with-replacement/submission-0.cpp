class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int res = 0;
        for(char c = 'A'; c <= 'Z'; c++) {
            int cnt = k, curRes = 0, cur = 0;
            for(int i = 0, j = 0; j < n; j++) {
                if(s[j] == c) {
                    ++cur;
                } else if(cnt) {
                    --cnt;
                    ++cur;
                } else {
                    while(s[i] == c) {
                        ++i;
                        --cur;
                    }
                    ++i;
                }

                curRes = max(curRes, cur);
            }

            res = max(res, curRes);
        }

        return res;
    }
};
