class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (auto& it : s) {
            switch (it) {
                case ')':
                    if (stk.empty() || stk.top() != '(') return false;
                    else stk.pop();
                    break;
                case ']':
                    if (stk.empty() || stk.top() != '[') return false;
                    else stk.pop();
                    break;
                case '}':
                    if (stk.empty() || stk.top() != '{') return false;
                    else stk.pop();
                    break;
                default:
                    stk.push(it);
            }
        }
        return stk.empty();
    }
};
