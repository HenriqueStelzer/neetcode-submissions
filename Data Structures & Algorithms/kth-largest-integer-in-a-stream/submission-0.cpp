class KthLargest {
public:
    multiset<int> tree;
    int i;
    KthLargest(int k, vector<int>& nums) {
        for (auto& it : nums) tree.insert(it);
        i = k;
    }
    
    int add(int val) {
        tree.insert(val);
        return *next(tree.begin(), tree.size()-i);
    }
};
