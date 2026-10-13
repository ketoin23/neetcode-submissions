class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN, curp = INT_MIN, curn = INT_MIN;
        for(auto i : nums) {
            res = max(res, i);
        }
        
        for(auto i : nums) {
            if(i == 0) {
                curp = INT_MIN;
                curn = INT_MIN;
            } else if(i > 0) {
                if(curp == INT_MIN) {
                    curp = i;
                } else {
                    curp *= i;
                }

                if(curn != INT_MIN) {
                    curn *= i;
                } 
            } else {
                if(curp == INT_MIN) {
                    if(curn == INT_MIN) {
                        curn = i;
                    } else {
                        curp = curn * i;
                        curn = i;
                    }
                } else {
                    if(curn == INT_MIN) {
                        curn = i * curp;
                        curp = INT_MIN;
                    } else {
                        int t = curn;
                        curn = curp * i;
                        curp = t * i;
                    }
                }
            }

            res = max(res, curp);
        }

        return res;
    }
};
