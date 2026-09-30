class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        if (grid[0][0] != 0 || grid[rows - 1][cols - 1] != 0) return -1;

        vector<vector<int>> visit(rows, vector<int>(cols, 0));

        queue<pair<int, int>> queue;
        queue.push(pair<int, int>(0,0));
        visit[0][0] = 1;

        int length = 1;
        while(!queue.empty()){
            int queueLength = queue.size();
            for( int i = 0 ; i < queueLength; i++){
                auto [r, c] = queue.front();
                queue.pop();

                if(r == rows - 1 && c == cols -1){
                    return length;
                }

                int neighbors[8][2] = {
                    {r - 1, c - 1},
                    {r - 1, c + 1},
                    {r + 1, c + 1},
                    {r + 1, c - 1},
                    {r , c - 1},
                    {r , c + 1},
                    {r - 1, c },
                    {r + 1, c },
                };

                for( int j = 0; j < 8; j++){
                    int newR = neighbors[j][0];
                    int newC = neighbors[j][1];

                    if(newR < 0 || newC < 0 || newR == rows || newC == cols || visit[newR][newC] || grid[newR][newC]) continue;
                    queue.push(pair<int,int>(newR, newC));
                    visit[newR][newC] = 1; 
                }
            }
            length++;
        }
        return -1;

    }
};