class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int> > heap;
    int n;
    KthLargest(int k, vector<int>& nums) {
        for (auto& it : nums) {
            heap.push(it);
            if (heap.size() > k) heap.pop();
        }
        n = k;
    }
    
    int add(int val) {
        heap.push(val);
        if (heap.size() > n) heap.pop();
        return heap.top();
    }
};
