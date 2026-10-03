class Solution {
    double f(double x, int n) {
        if(!n)
            return 1;
        double y = f(x, n / 2);
        y *= y;
        if(n & 1) {
            y *= x;
        }

        return y;
    }
public:
    double myPow(double x, int n) {
        double res = f(x, n);
        if(n < 0)
            return 1 / res;
        
        return res;
    }
};
