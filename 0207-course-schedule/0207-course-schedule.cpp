class Solution {
public:
bool dfs(int curr, vector<bool> &vis,vector<bool> &recpath,vector<vector<int>>& adj){
    vis[curr] = true;
    recpath[curr] = true;
    for(int v : adj[curr]){
        if(!vis[v]){
            if(dfs(v,vis,recpath,adj)){
                return true;
            }
        } else if(recpath[v]){
            return true;
        }
    }
    recpath[curr] = false;
    return false;

}
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        for(auto &egde:prerequisites){
            adj[egde[1]].push_back(egde[0]);
        }
        vector<bool> vis(n,false);
        vector<bool> recpath(n,false);
        for(int i =0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,vis,recpath,adj)){
                    return false;
                }
            }
        }
        return true;
    }
};