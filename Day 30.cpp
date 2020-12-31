// Game of Life

class Solution {
public:
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    int count(vector<vector<int>>& board, int m, int n, int x, int y) {
        if(x < 0 || y < 0 || x >= m || y >= n)
            return 0;
        return board[x][y];
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> temp = board;
        int m = board.size();
        int n = board[0].size();
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int cnt = 0;
                
                for(int x = 0; x < 8; x++) {
                    cnt += count(temp, m, n, i + dx[x], j + dy[x]);
                } 
                
                if(cnt < 2 || cnt > 3)
                    board[i][j] = 0;
                if(cnt == 3)
                    board[i][j] = 1;
            }
        }
    }
};