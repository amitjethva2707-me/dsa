/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        TreeNode* lastvisited = NULL;
        stack<TreeNode*> s;
        while(!s.empty() || curr != NULL){
            if(curr != NULL){
                s.push(curr);
                curr = curr->left;
            } else{
                TreeNode* temp = s.top();
                if(temp->right != NULL && lastvisited != temp->right){
                    curr = temp->right;
                } else {
                    ans.push_back(temp->val);
                    lastvisited = temp;
                    s.pop();
                }
            }
        }
        return ans;
    }
};