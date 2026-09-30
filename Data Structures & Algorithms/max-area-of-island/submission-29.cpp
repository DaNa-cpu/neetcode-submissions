class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> visit(rows, vector<int>(cols, 0));

        int maxArea = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 0 || visit[i][j]) continue;
                maxArea = max(maxArea, dfs(grid, i, j, visit));
            }
        }
        return maxArea;
    }
private:
    int dfs(vector<vector<int>>& grid, int r, int c, vector<vector<int>>& visit ){
        int rows = grid.size();
        int cols = grid[0].size(); 
        if(r < 0 || c < 0 || r == rows || c == cols || grid[r][c] == 0 || visit[r][c] == 1){
            return 0;
        }
        visit[r][c] = 1;
        return 1 + dfs(grid, r + 1, c, visit) +
            dfs(grid, r - 1, c, visit) +
            dfs(grid, r, c + 1, visit) +
            dfs(grid, r, c - 1, visit);

    }
};
