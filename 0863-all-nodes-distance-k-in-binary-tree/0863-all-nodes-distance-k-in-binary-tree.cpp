/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 class Solution {
public:
    
    // Map each node to its parent
    void makeParentMap(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }

            if (curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        // Step 1: Create parent map
        unordered_map<TreeNode*, TreeNode*> parent;
        makeParentMap(root, parent);

        // Step 2: BFS starting from target
        queue<TreeNode*> q;
        q.push(target);

        // To avoid visiting nodes again
        unordered_set<TreeNode*> visited;
        visited.insert(target);

        int distance = 0;

        // Step 3: BFS until we reach distance K
        while (!q.empty() && distance < k) {
            
            int size = q.size();

            // Process one complete level
            while (size--) {
                TreeNode* curr = q.front();
                q.pop();

                // Check left child
                if (curr->left && !visited.count(curr->left)) {
                    visited.insert(curr->left);
                    q.push(curr->left);
                }

                // Check right child
                if (curr->right && !visited.count(curr->right)) {
                    visited.insert(curr->right);
                    q.push(curr->right);
                }

                // Check parent
                if (parent.count(curr) && !visited.count(parent[curr])) {
                    visited.insert(parent[curr]);
                    q.push(parent[curr]);
                }
            }

            distance++;
        }

        // Step 4: Remaining nodes in queue are at distance K
        vector<int> ans;

        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};