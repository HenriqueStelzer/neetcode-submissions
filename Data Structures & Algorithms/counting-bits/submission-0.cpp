class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> count(n+1);
        for (int i = 0; i <= n; i++) count[i] = __popcount(i);
        return count;
    }
};
