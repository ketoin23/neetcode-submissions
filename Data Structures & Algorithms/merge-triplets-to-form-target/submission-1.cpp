class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> pos(3, 0);
        for(auto i : triplets) {
            bool ok = true;
            for(int j = 0; j < 3; j++) {
                if(i[j] > target[j])
                    ok = false;
            }
            
            if(!ok)
                continue;
            for(int j = 0; j < 3; j++) {
                pos[j] = max(pos[j], i[j]);
            }
        }

        return (pos == target);
    }
};
