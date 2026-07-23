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
                cur += '(';
                backtrack(n-1, open+1);
                cur.pop_back();
            }
            if (open > 0) {
                cur += ')';
                backtrack(n, open-1);
                cur.pop_back();
            }
        }
        else res.push_back(cur);
    }
};
