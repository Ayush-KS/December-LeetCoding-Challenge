// Diagonal Traverse

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return {};
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> op(m*n);
        int k = 0, x, y, inc;
        
        for(int i = 0; i < m + n - 1; i++) {
            inc = i&1 ? 1 : -1;
            if(i & 1) {
                if(i < n) {
                    x = 0, y = i;
                } else {
                    x = i - n + 1;
                    y = n - 1;
                }
            } else {
                if(i < m) {
                    x = i, y = 0;
                } else {
                    x = m - 1;
                    y = i - m + 1;
                }
            }
            while(x >= 0 && y >= 0 && x < m && y < n) {
                op[k++] = matrix[x][y];
                x += inc, y -= inc;
            }
        }
        
        return op;
    }
};