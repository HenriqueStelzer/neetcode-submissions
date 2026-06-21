class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> que;
        vector<int> awns(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++) {
            while (!que.empty() && temperatures[que.top()] < temperatures[i]) {
                awns[que.top()] = i - que.top();
                que.pop();
            }
            que.push(i);
        }

        return awns;
    }
};
