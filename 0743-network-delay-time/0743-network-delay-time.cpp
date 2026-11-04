class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &it : times){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
        }
        vector<int> dist(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>> > pq;
        pq.push({0,k});
        dist[k] = 0;
        while(!pq.empty()){
            auto[d,node] = pq.top();
            pq.pop();
            if(dist[node]<d){
                continue;
            }
            for(auto it : adj[node]){
                int adjnode = it.first;
                int wt = it.second;
                if(d+wt<dist[adjnode]){
                    dist[adjnode] = d+wt;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
        int ans = 0;
        for(int i =1;i<=n;i++){
            if(dist[i]==INT_MAX){
                return  -1;
            }
            ans = max(ans,dist[i]);
        }
        return ans;
    }
};