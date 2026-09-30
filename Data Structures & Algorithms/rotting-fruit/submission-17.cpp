class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       int rows = grid.size();
       int cols = grid[0].size();
       int fresh = 0;
       int time = 0;

       queue<pair<int,int>> queue;

       for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if( grid[i][j] == 1){
                    fresh++;
                }
                else if(grid[i][j] == 2){
                    queue.push(pair<int, int>(i,j));
                }
            }
       } 

       while( fresh && !queue.empty()){
            int queueLength = queue.size();
            for( int i = 0; i < queueLength; i++){
                auto [r,c] = queue.front();
                queue.pop();

                int neighbors[4][2] = {
                    {r, c + 1},
                    {r, c - 1},
                    {r + 1, c},
                    {r - 1, c}
                };

                for(int j = 0; j < 4; j++){
                    int newR = neighbors[j][0];
                    int newC = neighbors[j][1];

                    if( newR < 0 || newC < 0 || newR == rows || newC == cols || grid[newR][newC] != 1) continue;
                    queue.push(pair<int, int>(newR, newC));
                    grid[newR][newC] = 2;
                    fresh--;
                }
            }
            time++;
       }
    return fresh == 0 ? time : -1; 
    }
};
