class Solution {
public:

    TreeNode* helper(vector<int>& preorder,
                     vector<int>& inorder,
                     unordered_map<int, int>& mp,
                     int& preindex,
                     int left,
                     int right) {

        if (left > right) {
            return NULL;
        }

        // Preorder: Root -> Left -> Right
        TreeNode* root = new TreeNode(preorder[preindex]);

        // Find root position in O(1)
        int idx = mp[preorder[preindex]];

        preindex++;

        // Build left subtree
        root->left = helper(preorder, inorder, mp,
                            preindex, left, idx - 1);

        // Build right subtree
        root->right = helper(preorder, inorder, mp,
                             preindex, idx + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder,
                        vector<int>& inorder) {

        unordered_map<int, int> mp;

        // Store inorder value -> index
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        int preindex = 0;

        return helper(preorder, inorder, mp,
                      preindex, 0, inorder.size() - 1);
    }
};