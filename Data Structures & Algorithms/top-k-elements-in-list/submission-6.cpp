class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (auto& it : nums) {
            if (m.contains(it)) m[it]++;
            else m[it] = 1;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto& it : m) {
            if (pq.size() < k) pq.push({it.second, it.first});
            else if (pq.top().first < it.second) {
                pq.pop();
                pq.push({it.second, it.first});
            }
        }
        vector<int> aws;
        while (!pq.empty()) {
            aws.push_back(pq.top().second);
            pq.pop();
        }
        return aws;
    }
};
