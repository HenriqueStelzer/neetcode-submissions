class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0, low = 10e5, high = 0;
        for (int& it : prices) {
            if (it > high) {
                high = it;
            }
            if (it < low) {
                low = it;
                high = 0;
            }
            maxP = max(maxP, high - low);
        }
        return maxP;
    }
};