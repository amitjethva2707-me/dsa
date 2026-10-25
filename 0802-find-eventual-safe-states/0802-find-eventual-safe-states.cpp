class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph,
             vector<int>& vis, vector<int>& path,
             vector<int>& safe) {

        vis[node] = 1;
        path[node] = 1;

        for (int v : graph[node]) {
            if (!vis[v]) {
                if (!dfs(v, graph, vis, path, safe))
                    return false;
            }
            else if (path[v]) {
                return false;
            }
        }

        path[node] = 0;
        safe[node] = 1;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> vis(n, 0);
        vector<int> path(n, 0);
        vector<int> safe(n, 0);
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, graph, vis, path, safe);
            }
        }

        for (int i = 0; i < n; i++) {
            if (safe[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};