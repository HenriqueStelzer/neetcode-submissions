class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for (auto& it : tokens) {
            if (it.size() == 1 && it[0] < '0') {
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
            else {
                int x = 0, n = it.size(), mult = 1, i = 0;
                if (it[0] == '-') {
                    mult = -1;
                    i = 1;
                }
                while (i < n) {
                    x += mult * (pow(10, n-1-i) * (it[i]-'0'));
                    i++;
                }
                nums.push(x);
            }
        }
        return nums.top();
    }
};
