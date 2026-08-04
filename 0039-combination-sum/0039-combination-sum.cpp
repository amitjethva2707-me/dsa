class Solution {
public:
    void helper(vector<int>& candidates, int i, int tar,
                vector<int>& curr, vector<vector<int>>& ans) {

        if (tar == 0) {
            ans.push_back(curr);
            return;
        }

        if (i == candidates.size() || tar < 0) {
            return;
        }

        // Pick current element
        curr.push_back(candidates[i]);
        helper(candidates, i, tar - candidates[i], curr, ans);
        curr.pop_back();

        // Skip current element
        helper(candidates, i + 1, tar, curr, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(candidates, 0, target, curr, ans);
        return ans;
    }
};
