class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comp = [](auto& a, auto& b){
            return sqrt(a[0]*a[0] + a[1]*a[1]) < sqrt(b[0]*b[0] + b[1]*b[1]);
        };
        priority_queue<vector<int>, vector<vector<int> >, decltype(comp) > que;
        for (auto it : points) {
            que.push(it);
            if (que.size() > k) que.pop();
        }
        vector<vector<int> > aws;
        while(!que.empty()) {
            aws.push_back(que.top());
            que.pop();
        }
        return aws;
    }
};
