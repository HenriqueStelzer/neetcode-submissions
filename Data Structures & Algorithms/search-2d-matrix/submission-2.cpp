class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int s, v;
        int n = matrix.size(), m = matrix[0].size();
        int f=0, l=n*m-1;
        while (f <= l) {
            s = (f + l) / 2;
            v = matrix[s/m][s%m];

            if (target > v) f = s+1;
            else if (target < v) l = s-1;
            else return true;
        }

        return false;
    }
};
