class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x = 0;
        for(int i = 1; i <= nums.size(); i++) {
            x = (x ^ i);
        }

        int y = 0;
        for(auto i : nums) {
            y = (y ^ i);
        }

        return (x ^ y);
    }
};

/*
000 -> 000
001 -> 001
010 -> 011
011 -> 000
100 -> 100
101 -> 001
110 -> 111
111 -> 000
*/