class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<int> id(n);
        iota(id.begin(), id.end(), 0);
        sort(id.begin(), id.end(), [&position](auto& a, auto& b) {
            return position[a] > position[b];
        });
        double ceiling = 0;
        int count = 0;
        for (auto it : id) {
            if (((target - position[it]) / (double)speed[it]) > ceiling) {
                count++;
                ceiling = ((target - position[it]) / (double)speed[it]);
            }
        }
        return count;
    }
};
