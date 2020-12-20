// Cherry Pickup II 

class Solution {
public:
    
    int helper(vector<vector<int>>& grid, vector<vector<vector<vector<int>>>>& dp , int r1, int c1, int r2, int c2, int row, int col) {
        if(r1 < 0 || r1 >= row || c1 < 0 || c1 >= col || r2 < 0 || r2 >= row || c2 < 0 || c2 >= col)
            return 0;
        if(dp[r1][c1][r2][c2] != -1)
            return dp[r1][c1][r2][c2];
        
        int ans = grid[r1][c1] + grid[r2][c2];
        if(r1 == r2 && c1 == c2) {
            ans -= grid[r1][c1];
        }
        int smallAns = 0;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                smallAns = max(smallAns, helper(grid, dp, r1 + 1, c1 + (i - 1), r2 + 1, c2 + (j - 1), row, col));
            }
        }
        dp[r1][c1][r2][c2] = smallAns + ans;
        return dp[r1][c1][r2][c2];
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<vector<vector<int>>>> dp (row, vector<vector<vector<int>>>(col, vector<vector<int>>(row, vector<int>(col, -1))));
        return helper(grid, dp, 0, 0, 0, col - 1, row, col);
    }
};