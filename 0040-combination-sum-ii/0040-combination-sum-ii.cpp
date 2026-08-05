class Solution {
public:
    void helper(vector<int>& candidates, int idx, int target,
                vector<int>& curr, vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        if (idx == candidates.size() || target < 0)
            return;

        // TAKE current element (use it only once)
        curr.push_back(candidates[idx]);
        helper(candidates, idx + 1, target - candidates[idx], curr, ans);
        curr.pop_back();

        // NOT TAKE current element
        int next = idx + 1;

        // Skip all duplicates
        while (next < candidates.size() &&
               candidates[next] == candidates[idx]) {
            next++;
        }

        helper(candidates, next, target, curr, ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> curr;

        helper(candidates, 0, target, curr, ans);

        return ans;
    }
};