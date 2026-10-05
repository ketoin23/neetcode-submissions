class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st1, st2;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                st1.push(i);
            } else if(s[i] == '*') {
                st2.push(i);
            } else {
                if(!st1.empty()) {
                    st1.pop();
                } else if(!st2.empty()) {
                    st2.pop();
                } else {
                    return false;
                }
            }
        }

        if(st1.size() > st2.size())
            return false;
        
        while(!st1.empty()) {
            int x = st1.top();
            int y = st2.top();

            if(x > y)
                return false;
            
            st1.pop();
            st2.pop();
        }

        return true;
    }
};
