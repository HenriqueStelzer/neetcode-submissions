class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for (auto& it : tokens) {
            if (it == "+" || it == "-" || it == "*" || it == "/") {
                int n1 = nums.top(); nums.pop();
                int n2 = nums.top(); nums.pop();
                switch (it[0]) {
                    case '+':
                        nums.push(n2 + n1);
                        break;
                    case '-':
                        nums.push(n2 - n1);
                        break;
                    case '*':
                        nums.push(n2 * n1);
                        break;
                    case '/':
                        nums.push(n2 / n1);
                        break;
                }
            }
            else nums.push(stoi(it));
        }
        return nums.top();
    }
};
