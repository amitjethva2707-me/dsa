class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }
        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 1});
        grid[0][0] = 1;
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        while (!q.empty()) {
            auto front = q.front();
            int row = front.first.first;
            int col = front.first.second;
            int dist = front.second;
            q.pop();
            if (row == n - 1 && col == n - 1) {
                return dist;
            }
            for (int i = 0; i < 8; i++) {
                int nr = row + dx[i];
                int nc = col + dy[i];
                if(nr>= 0 && nc>=0 && nr<n && nc<n && grid[nr][nc] == 0){
                    grid[nr][nc] = 1;
                    q.push({{nr,nc},dist+1});
                }
            }
        }
        return -1;
    }
};