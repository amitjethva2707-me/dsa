class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int inf = 1e9;
        vector<vector<int>> dist(n,vector<int>(n,inf));
        for(int i =0;i<n;i++){
            dist[i][i] =0;
        }
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            dist[u][v] = wt;
            dist[v][u] = wt;

        }
        for(int k =0;k<n;k++){
            for(int i =0;i<n;i++){
                for(int j =0;j<n;j++){
                    if(dist[i][k] != inf && dist[k][j] != inf){
                        dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);

                    }
                }
            }
        }
        int mincount = n;
        int ans = -1;
        for(int i =0;i<n;i++){
            int count =0;
            for(int j =0;j<n;j++){
                if(i!= j && dist[i][j]<=distanceThreshold){
                    count++;
                }
            }
            if(count<=mincount){
                mincount = count;
                ans = i;

            }
        }
        return ans;
    }
};