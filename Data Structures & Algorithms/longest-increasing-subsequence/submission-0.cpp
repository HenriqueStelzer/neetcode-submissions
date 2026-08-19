#define all(x) x.begin(), x.end()

struct SqrtSegMax {
    int n, m;
    vector<int> a, b;

    SqrtSegMax (int n) : a(n), n(n) {
        m = sqrt(n);
        b.assign((n + m-1) / m, 0);
    }

    void update (int idx, int val) {
        a[idx] = max(a[idx], val);
        b[idx/m] = max(b[idx/m], a[idx]);
    }

    int query(int idx) {
        int mx = 0;
        
        int full = idx/m;
        for (int i = 0; i < full; i++) mx = max(mx, b[i]);
        for (int i = m * full; i < idx; i++) mx = max(mx, a[i]);

        return mx;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> comp(n);
        for (int i = 0; i < n; i++) comp[i] = nums[i];
        sort(all(comp));
        comp.erase(unique(all(comp)), comp.end());
        
        auto cntSortMax = SqrtSegMax(comp.size()+1);

        int mx = 0;
        for (int i = 0; i < n; i++) {
            int idx = lower_bound(all(comp), nums[i]) - comp.begin() + 1;
            nums[i] = cntSortMax.query(idx);
            cntSortMax.update(idx, nums[i]+1);
            mx = max(mx, nums[i]);
        }

        return mx+1;
    }
};
