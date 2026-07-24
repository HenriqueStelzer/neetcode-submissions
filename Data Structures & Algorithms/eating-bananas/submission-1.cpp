class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int m = 0;
        for (auto& it : piles) m = max(m, it);
        int l = 1, r = m;
        int last = 1e9; // max piles[i] possible
        int lastc = m; // worst case
        while (l <= r) {
            int c = (l + r) / 2;
            int cur = 0;
            for (auto& it : piles) {
                cur += (it + c-1) / c;
            }
            if (cur <= h) {
                last = cur;
                lastc = min(lastc, c);
                r = c-1;
            }
            else {
                l = c+1;
            }
        }
        return lastc;
    }
};
