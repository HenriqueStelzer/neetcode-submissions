class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        array<int16_t, 1001> count{};
        for (int i = 0; i < hand.size(); i++) count[hand[i]]++;
        int sum = 0;
        for (int i = 0; i <= 1000; i++) {
            if (count[i] > 0) {
                if (i+groupSize >= 1000) return false;
                int x = count[i];
                for (int j = i; j < i+groupSize; j++) {
                    count[j] -= x;
                }
            }
            sum += count[i];
        }
        return (sum == 0);
    }
};
