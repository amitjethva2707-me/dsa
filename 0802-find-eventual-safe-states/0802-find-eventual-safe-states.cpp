class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
     int n = graph.size();
     vector<vector<int>> adj(n);
     vector<int> outdegree(n,0);
     queue<int> q;
     vector<int> ans;
     for(int i = 0;i<n;i++){
        outdegree[i] = graph[i].size();
        for(int v : graph[i]){
           adj[v].push_back(i);
        }
     }
     for(int i =0;i<n;i++){
        if(outdegree[i] == 0){
            q.push(i);
        }
     }
     while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(int prev : adj[node]){
            outdegree[prev]--;
            if(outdegree[prev] == 0){
                q.push(prev);
            }
        }
     }
     sort(ans.begin(),ans.end());
     return ans;
    }
};