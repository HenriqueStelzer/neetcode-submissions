class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        long long x = 0;
        for (int i = 0; i < digits.size(); i++) {
            x += (digits[digits.size()-1-i] * pow(10, i));
        }
        x++;
        vector<int> aws;
        for (auto& it : to_string(x)) {
            aws.push_back(it - '0');
        }
        return aws;
    }
};
