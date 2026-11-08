class Solution {
public:
    int n, m;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int dfs(int i, int j, int id, vector<vector<int>>& grid) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != 1) {
            return 0;
        }
        grid[i][j] = id;
        int size = 1;
        for (int k = 0; k < 4; k++) {
            int nr = i + dx[k];
            int nc = j + dy[k];
            size += dfs(nr, nc, id, grid);
        }
        return size;
    }
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        unordered_map<int, int> mp;
        int id = 2;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int size = dfs(i, j, id, grid);
                    mp[id] = size;
                    ans = max(ans, size);
                    id++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    set<int> st;
                    for (int k = 0; k < 4; k++) {
                        int nr = i + dx[k];
                        int nc = j + dy[k];
                        if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
                            grid[nr][nc] > 1) {
                            st.insert(grid[nr][nc]);
                        }
                    }
                    int total = 1;
                    for (int s : st) {
                        total += mp[s];
                    }
                    ans = max(ans, total);
                }
            }
        }
        return ans;
    }
};