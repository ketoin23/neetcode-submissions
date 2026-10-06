class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0, cnt = 31;
        while(1) {
            uint32_t sig = n & 1;
            n /= 2;
            sig = (sig << cnt);
            res += sig;
            if(!cnt)
                break;
            --cnt;
        }

        return res;
    }
};
