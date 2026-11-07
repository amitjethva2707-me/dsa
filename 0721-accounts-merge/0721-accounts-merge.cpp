
class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Path Compression
    int findUPar(int node) {
        if (parent[node] == node) {
            return node;
        }

        return parent[node] = findUPar(parent[node]);
    }

    // Union by Size
    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(
        vector<vector<string>>& accounts) {

        int n = accounts.size();

        // Step 1: Email mapping
        unordered_map<string, int> emailToId;
        unordered_map<int, string> idToEmail;
        unordered_map<string, string> emailToName;

        int id = 0;

        for (auto &account : accounts) {
            for (int i = 1; i < account.size(); i++) {

                string email = account[i];

                if (emailToId.find(email) == emailToId.end()) {

                    emailToId[email] = id;
                    idToEmail[id] = email;
                    emailToName[email] = account[0];

                    id++;
                }
            }
        }

        // Step 2: Initialize DSU
        DisjointSet ds(id);

        // Step 3: Union emails belonging to same account
        for (auto &account : accounts) {

            int first = emailToId[account[1]];

            for (int i = 2; i < account.size(); i++) {

                int curr = emailToId[account[i]];

                ds.unionBySize(first, curr);
            }
        }

        // Step 4: Group emails by ultimate parent
        unordered_map<int, vector<string>> mp;

        for (auto &it : emailToId) {

            string email = it.first;
            int emailId = it.second;

            int root = ds.findUPar(emailId);

            mp[root].push_back(email);
        }

        // Step 5: Construct final answer
        vector<vector<string>> ans;

        for (auto &it : mp) {

            vector<string> emails = it.second;

            // Sort emails lexicographically
            sort(emails.begin(), emails.end());

            vector<string> temp;

            // Add account name
            temp.push_back(emailToName[emails[0]]);

            // Add sorted emails
            for (auto &email : emails) {
                temp.push_back(email);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
