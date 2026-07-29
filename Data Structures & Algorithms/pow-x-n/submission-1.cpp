class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) {
            x = 1 / x;
            n = n * -1;
        }
        if (n == 0) return (double) 1;
        double res = 1, cur = x;
        for (int i = 0; i < 32; i++) {
            if (1<<i & n) res *= cur;
            cur = cur * cur;
        }
        return res;
    }
};
