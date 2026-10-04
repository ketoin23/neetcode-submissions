class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> mp;
        for(auto i : hand) {
            mp[i]++;
        }

        while(mp.size()) {
            int val = (*mp.begin()).first;
            int cnt = (*mp.begin()).second;

            for(int i = val; i - val + 1 <= groupSize; i++) {
                mp[i] -= cnt;
                if(mp[i] < 0)
                    return false;
                
                if(mp[i] == 0) {
                    mp.erase(i);
                }
            }
        }

        return true;
    }
};
