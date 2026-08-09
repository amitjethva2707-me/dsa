class Solution {
public:
    int f(vector<vector<int>>& grid, int r, int c, int count, int total) {
        int n = grid.size();
        int m = grid[0].size();
        if (r < 0 || c < 0 || r >= n || c >= m || grid[r][c] == -1) {
            return 0;
        }
        if (grid[r][c] == 2) {
            if (count == total) {
                return 1;
            }
            return 0;
        }
        grid[r][c] = -1;
        int path = 0;
        path += f(grid, r + 1, c, count + 1, total);
        path += f(grid, r, c + 1, count + 1, total);
        path += f(grid, r - 1, c, count + 1, total);
        path += f(grid, r, c - 1, count + 1, total);
        
        grid[r][c] = 0;
        return path;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int sr;
        int sc;
        int total = 0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]!=-1){
                    total++;
                }
                if(grid[i][j] == 1){
                    sr =i; 
                    sc = j;
                }
            }
        }
        return f(grid,sr,sc,1,total);
    }
};