class Solution {
public:
    bool isHappy(int n) {
        set<int> vis;
        while (n != 1) {
            string m = to_string(n);
            n = 0;
            for (auto& it : m) n += (it-'0') * (it-'0');
            if (vis.contains(n)) return false;
            vis.insert(n);
        }
        return true;
    }
};
