class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int mod = 1e9 + 7;
        vector<vector<pair<int, int>>> adj(n);
        for (auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int wt = road[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>> pq;
        
        pq.push({0,0});
        while(!pq.empty()){
            auto[d,u] = pq.top();
            pq.pop();
            if(d > dist[u]){
                continue;
            }
            for(auto &[v,wt] :adj[u] ){
                long long newdist = d+wt;
                if(newdist<dist[v]){
                    dist[v] = newdist;
                    ways[v]= ways[u];
                    pq.push({newdist,v});
                } else if(newdist == dist[v]){
                    ways[v] = (ways[v]+ways[u])%mod;
                }
            }
        }
        return ways[n-1];
            
    }
};