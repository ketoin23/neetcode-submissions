class Solution {
public:
    vector<int> countBits(int n) {
        if(!n)
            return {0};
        vector<int> res{0, 1};
        int pow = 2, cnt = 0;
        for(int i = 2; i <= n; i++) {
            res.push_back(1 + res[i - pow]);
            ++cnt;

            if(cnt == pow) {
                pow *= 2;
                cnt = 0;
            }
        } 

        return res;
       /*
        0
        1
        10 -> 1 + 0 -2
        11 -> 1 + 1 -2
        100 -> 1 + 00 -4
        101 -> 1 + 01 -4
        110 -> 1 + 10 -4
        111 -> 1 + 11 -4
        1000 -> 1 + 000 -8
        1001 -> 1 + 001 -8
        1010 -> 1 + 010
        1011 -> 1 + 011
        1100 -> 1 + 100
        1101 -> 1 + 101
        1110 -> 1 + 110
        1111 -> 1 + 111
       */
    }
};
