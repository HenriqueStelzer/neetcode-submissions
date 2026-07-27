class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int cur=0, sum=0, res=-1;
        for (int i = 0; i < gas.size(); i++) {
            cur = gas[i] - cost[i];
            sum += cur;
            if (res == -1) {
                if (cur >= 0) res = i;
            }
            else if (sum < 0) res = -1;
            // cout << sum << ' ' << cur << ' ' << res << '\n';
        }
        if (sum < 0) return -1;
        return res; 
    }
};
