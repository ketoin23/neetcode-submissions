class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //-1, 0, -1, 3
        //-1, -1, 1

        int n = gas.size(), sum = 0;
        for(int i = 0; i < n; i++) {
            gas[i] -= cost[i];
            sum += gas[i];
        }

        if(sum < 0)
            return -1;
        
        int res = 0;
        sum = 0;
        for(int i = 0; i < n; i++) {
            sum += gas[i];
            if(sum < 0) {
                res = i + 1;
                sum = 0;
            }
        }

        return res;
    }
};
