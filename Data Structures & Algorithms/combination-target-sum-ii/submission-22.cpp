class Solution {
vector<vector<int>> res;
vector<int> cur;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0);
        return res;
    }
private:
    void backtrack(vector<int>& candidates, int target, int start) {
        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > target) continue;
            if (i > start && candidates[i] == candidates[i-1]) continue;
            cur.push_back(candidates[i]);
            if (candidates[i] == target) res.push_back(cur);
            else backtrack(candidates, target-candidates[i], i+1);
            cur.pop_back();
        }
    }
};
