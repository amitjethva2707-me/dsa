class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        dist[0][0] = grid[0][0];
        pq.push({grid[0][0],0,0});
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int time = it[0];
            int r = it[1];
            int c = it[2];
            if(r == n-1 && c == n-1){
                return time;
            }
            if(time > dist[r][c]){
                continue;
            }
            for(int i =0;i<4;i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr >=0 && nc>=0 && nr<n && nc<n){
                    int newtime = max(time,grid[nr][nc]);
                    if(newtime<dist[nr][nc]){
                        dist[nr][nc] = newtime;
                        pq.push({dist[nr][nc],nr,nc});
                    }
                }
            }
        }
        return -1;
    }
};