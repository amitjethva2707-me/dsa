class Solution {
public:
void helper(vector<int>& arr, int idx, int target,
                vector<int>& curr, vector<vector<int>>& ans,int k) {
    if(curr.size() == k){
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
    }

        if (idx == arr.size() || target < 0)
            return;

        // TAKE current element (use it only once)
        curr.push_back(arr[idx]);
        helper(arr, idx + 1, target - arr[idx], curr, ans,k);
        curr.pop_back();



        helper(arr,idx+1, target, curr, ans,k);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ans;
        vector<int> curr;
        helper(arr,0,n,curr,ans,k);
        return ans;
    }
};