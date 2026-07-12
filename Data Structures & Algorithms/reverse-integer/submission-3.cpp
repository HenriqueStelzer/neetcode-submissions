class Solution {
public:
    int reverse(int x) {
        int sign = 1;
        if (x < 0) {
            sign = -1;
            x *= -1;
        }

        int y = 0;
        int n = log10(x);
        for (int i = 0; i <= n; i++) {
            int a = x % 10;
            x /= 10;
            if (y + a/10 > (pow(2, 31) -1) / 10) return 0;
            y *= 10;
            y += a;
        }

        return y * sign;
    }
};
