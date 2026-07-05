class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> que;        
        for (auto& it : stones) que.push(it);
        while (que.size() > 1) {
            int a = que.top(); que.pop();
            int b = que.top(); que.pop();
            que.push(max(a-b, 0));
        }
        return que.top();
    }
};
