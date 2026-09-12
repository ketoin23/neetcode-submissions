class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0, cnt = 0;
        while((1<<cnt) <= n) {
            if((1<<cnt) & n)
                ++res;
            ++cnt;
        }

        return res;
    }
};
