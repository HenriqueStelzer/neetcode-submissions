class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        bool pending = true;
        for (auto& it : intervals) {
            if (pending && newInterval[0] <= it[1] && newInterval[1] >= it[0]) {
                newInterval[0] = min(newInterval[0], it[0]);
                newInterval[1] = max(newInterval[1], it[1]);
            }
            else if (pending && newInterval[1] < it[0]) {
                res.push_back(newInterval);
                res.push_back(it);
                pending = false;
            }
            else res.push_back(it);
        }
        if (pending) res.push_back(newInterval);
        return res;
    }
};
