class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        multiset<int> ms;
        unordered_set<int> s;
        for (auto& it : nums) {
            s.insert(it);
            ms.insert(it);
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto& it : s) {
            int cnt = ms.count(it);
            cout << it << ' ' << cnt << '\n';
            if (pq.size() < k) pq.push({cnt, it});
            else if (pq.top().first < cnt) {
                pq.pop();
                pq.push({cnt, it});
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
