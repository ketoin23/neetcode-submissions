class Solution {
    int f(int x) {
        int res = 0;
        while(x) {
            int n = x % 10;
            res += n * n;
            x /= 10;
        }

        return res;
    }
public:
    bool isHappy(int n) {
        set<int> st{n};
        while(1) {
            n = f(n);
            if(st.find(n) != st.end())
                break;

            st.insert(n);
        }

        if(st.find(1) != st.end())
            return true;
        return false;
    }
};
