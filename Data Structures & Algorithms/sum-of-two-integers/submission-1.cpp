class Solution {
public:
    int getSum(int a, int b) {
        int base = a ^ b;
        int carry = (a & b) << 1;
        while(carry) {
            int ncarry = (base & carry) << 1;
            base = (base ^ carry);
            carry = ncarry;
        }

        return base;

        /* 
        a = 010100
        b = 011110
        a+b = 110010
        a^b = 001010
        a&b = 010100
        a&b << 1 = 101000
        a|b = 011110

        base -> a ^ b 0+1 = 1 in binary
        carry over -> account for 1 + 1 with a & b shifted to the left 
        because 1 + 1 = 10 in binary
        now change the base to base ^ carry over because with the carry we still take care of 1 + 0 = 1
        now the carry might affect 1 + 1 again so the new carry is base & carry and left shift, till carry is 0
         */
    }
};

/*
a = 100
b = 111
base = 0011
carry = 1000
base = 1011
carry = 0
*/
