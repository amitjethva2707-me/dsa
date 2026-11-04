
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        // {time, row, col}
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], 0, 0});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!pq.empty()) {

            auto [time, r, c] = pq.top();
            pq.pop();

            if (r == n - 1 && c == n - 1) {
                return time;
            }

            if (time > dist[r][c]) {
                continue;
            }

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nc >= 0 && nr < n && nc < n) {

                    int newTime = max(time, grid[nr][nc]);

                    if (newTime < dist[nr][nc]) {
                        dist[nr][nc] = newTime;

                        pq.push({newTime, nr, nc});
                    }
                }
            }
        }

        return -1;
    }
};
