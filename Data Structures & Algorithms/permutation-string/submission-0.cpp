class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.size() > s2.size())
            return false;

        vector<int> a(26, 0), b(26, 0);
        for(auto i : s1) {
            a[i - 'a']++;
        }

        for(int i = 0; i < s1.size(); i++) {
            b[s2[i] - 'a']++;
        }    

        if(a == b)
            return true;
        
        for(int i = 0, j = s1.size(); j < s2.size(); j++, i++) {
            b[s2[i] - 'a']--;
            b[s2[j] - 'a']++;
            if(a == b)
                return true;
        }

        return false;
    }
};
