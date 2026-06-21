class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        
        array<int, 26> a;
        for (auto& it : s) a[it - 'a']++;
        for (auto& it : t) a[it - 'a']--;

        for (auto& it : a) if (it != 0) return false;
        return true;
    }
};
