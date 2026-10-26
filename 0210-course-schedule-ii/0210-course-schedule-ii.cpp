class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        vector<int> ans;
        queue<int> q;

        for (auto& edge : prerequisites) {
            int course = edge[0];
            int prereq = edge[1];

            adj[prereq].push_back(course);
            indegree[course]++;
        }

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            ans.push_back(curr);

            for (int v : adj[curr]) {
                indegree[v]--;

                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        if (ans.size() != n) {
            return {};
        }

        return ans;
    }
};