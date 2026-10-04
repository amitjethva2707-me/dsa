class Solution {
public:

    TreeNode* helper(vector<int>& postorder,
                     vector<int>& inorder,
                     unordered_map<int, int>& mp,
                     int& postindex,
                     int left,
                     int right) {

        if (left > right) {
            return NULL;
        }

        // Postorder: Left -> Right -> Root
        // Process from right to left, so root comes first
        TreeNode* root = new TreeNode(postorder[postindex]);

        // Find root position in inorder
        int idx = mp[postorder[postindex]];

        postindex--;

        // IMPORTANT: Build RIGHT first
        root->right = helper(postorder, inorder, mp,
                             postindex, idx + 1, right);

        // Then build LEFT
        root->left = helper(postorder, inorder, mp,
                            postindex, left, idx - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder,
                        vector<int>& postorder) {

        unordered_map<int, int> mp;

        // Store inorder value -> index
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        int postindex = postorder.size() - 1;

        return helper(postorder, inorder, mp,
                      postindex, 0, inorder.size() - 1);
    }
};