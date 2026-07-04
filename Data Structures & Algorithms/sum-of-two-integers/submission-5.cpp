class Solution {
public:
    int getSum(int a, int b) {
        bool last = false;
        int x = 0;
        for (int i = 0; i < 32; i++) {
            bool a_bit = (1<<i) & a;
            bool b_bit = (1<<i) & b;
            if (a_bit ^ b_bit ^ last) x += 1<<i;
            if ((a_bit & b_bit) || (a_bit & last) || (last & b_bit)) last = true;
            else last = false;
        }
        return x;
    }
};
