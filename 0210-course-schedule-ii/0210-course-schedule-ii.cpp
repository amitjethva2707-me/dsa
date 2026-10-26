class Solution {
public:
    bool dfs(int curr, vector<bool>& vis, vector<bool>& recpath,
             vector<vector<int>>& adj, vector<int>& ans) {
        vis[curr] = true;
        recpath[curr] = true;
        for (int v : adj[curr]) {
            if (!vis[v]) {
                if (dfs(v, vis, recpath, adj,ans)) {
                    return true;
                }
            } else if (recpath[v]) {
                return true;
            }
        }
        recpath[curr] = false;
        ans.push_back(curr);
        return false;
    }

    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
          vector<vector<int>> adj(n);
          vector<int> ans;
        for(auto &egde:prerequisites){
            adj[egde[0]].push_back(egde[1]);
        }
        vector<bool> vis(n,false);
        vector<bool> recpath(n,false);
        for(int i =0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,vis,recpath,adj,ans)){
                    return {};
                }
            }
        }
        return  ans;
    }
};