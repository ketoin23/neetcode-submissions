class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 0, add = 1;
        for(int i = n - 1; i > -1; i--) {
            if(digits[i] + add + carry > 9) {
                digits[i] = 0;
                carry = 1;
            } else {
                digits[i] += add + carry;
                carry = 0;
                break;
            }

            add = 0;
        }

        if(carry) {
            reverse(digits.begin(), digits.end());
            digits.push_back(1);
            reverse(digits.begin(), digits.end());
        }

        return digits;
    }
};
