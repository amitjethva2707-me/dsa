class Solution {
public:
int time;
vector<int> dt,low;
void dfs(int u ,int par,vector<vector<int>>& adj,vector<vector<int>>& ans){
    dt[u] = low[u] = ++time;
    for(int i =0;i<adj[u].size();i++){
        int v = adj[u][i];
        if(dt[v] == -1){
            dfs(v,u,adj,ans);
            low[u] = min(low[u],low[v]);
            if(low[v] >dt[u]){
              ans.push_back({u,v});
            }
        } else if(v != par){
                low[u] = min(low[u],dt[v]);
        }
    }

}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(int i =0;i<connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        time = 0;
        dt.resize(n,-1);
        low.resize(n);
        vector<vector<int>> ans;
        for(int i =0;i<n;i++){
            if(dt[i] == -1){
                dfs(i,-1,adj,ans);
            }
        }
        return ans;

    }
};