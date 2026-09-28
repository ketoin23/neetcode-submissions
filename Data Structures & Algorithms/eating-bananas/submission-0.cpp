class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 0, r = INT_MAX;

        while(l + 1 < r) {
            int m = l + (r - l) / 2;

            int ch = h;
            for(auto i : piles) {
                ch -= (i + m - 1) / m;
                if(ch < 0)
                    break;
            }

            if(ch < 0) {
                l = m;
            } else {
                r = m;
            }
        }

        return r;
    }
};
