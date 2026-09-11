class Solution {
    bool check(char c) {
        if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
            return true;

        return false;
    }
public:
    bool isPalindrome(string s) {
        for(int i = 0, j = s.size() - 1; i < j; i++, j--) {
            while(i < j && !check(s[i]))
                ++i;
            while(i < j && !check(s[j]))
                --j;

            if(s[i] <= '9' && s[i] >= '0') {
                if(s[i] != s[j])
                    return false;
            } else {
                if(s[i] == s[j] || toupper(s[i]) == s[j] || tolower(s[i]) == s[j])
                    continue;
                                
                return false;
            }
        }

        return true;
    }
};
