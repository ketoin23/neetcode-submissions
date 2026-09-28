class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        if(matrix[0][0] > target)
            return false;
        if(matrix[n - 1][m - 1] < target)
            return false;

        int l = 0, r = n - 1;
        while(l < r) {
            int mid = (l + r) / 2;
            if(matrix[mid][0] > target) {
                r = mid - 1;
            } else if(matrix[mid][m - 1] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        
        int row = l;
        l = 0, r = m - 1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(matrix[row][mid] > target) {
                r = mid - 1;
            } else if(matrix[row][mid] < target) {
                l = mid + 1;
            } else {
                return true;
            }
        }

        return false;
    }
};
