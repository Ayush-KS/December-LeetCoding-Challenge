// Spiral Matrix II

class Solution {
public:  
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> grid(n, vector<int>(n));
        int k = 1;
        for(int i = 0; i < n/2; i++) {
            for(int j = i; j < n - i; j++) {
                grid[i][j] = k++;
            }
            for(int j = i + 1; j < n - i; j++) {
                grid[j][n - 1 - i] = k++;
            }
            for(int j = n - i - 2; j >= i; j--) {
                grid[n - 1 - i][j] = k++;
            }
            for(int j = n - 2 - i; j > i; j--) {
                grid[j][i] = k++;
            }
        }
        
        if(n&1)
            grid[n/2][n/2] = k;
        
        return grid;
    }
};