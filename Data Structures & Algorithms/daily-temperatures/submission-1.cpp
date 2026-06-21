class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk;
        vector<int> awns(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++) {
            while (!stk.empty() && temperatures[stk.top()] < temperatures[i]) {
                awns[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }

        return awns;
    }
};
