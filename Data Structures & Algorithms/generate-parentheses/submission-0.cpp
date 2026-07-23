class Solution {
vector<string> res;
string cur = "";
public:
    vector<string> generateParenthesis(int n) {
        backtrack(n, 0);
        return res;
    }
private:
    void backtrack(int n, int open) {
        if (n || open) {
            if (n > 0) {
                string old = cur;
                cur += '(';
                backtrack(n-1, open+1);
                cur = old;
            }
            if (open > 0) {
                string old = cur;
                cur += ')';
                backtrack(n, open-1);
                cur = old;
            }
        }
        else res.push_back(cur);
    }
};
