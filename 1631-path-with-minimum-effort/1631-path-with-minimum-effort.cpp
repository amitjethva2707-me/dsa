class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        dist[0][0] = 0;

        // {effort, row, col}
        pq.push({0, 0, 0});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!pq.empty()) {

            auto front = pq.top();

            int effort = get<0>(front);
            int row = get<1>(front);
            int col = get<2>(front);

            pq.pop();

            if (effort > dist[row][col]) {
                continue;
            }

            if (row == n - 1 && col == m - 1) {
                return effort;
            }

            for (int i = 0; i < 4; i++) {

                int nr = row + dr[i];
                int nc = col + dc[i];

                if (nr >= 0 && nc >= 0 && nr < n && nc < m) {

                    int edgeeffort = abs(
                        heights[nr][nc] - heights[row][col]
                    );

                    int neweffort = max(edgeeffort, effort);

                    if (neweffort < dist[nr][nc]) {

                        dist[nr][nc] = neweffort;

                        pq.push({neweffort, nr, nc});
                    }
                }
            }
        }

        return 0;
    }
};