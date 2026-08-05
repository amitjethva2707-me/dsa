class Solution {
public:
    void helper(vector<int> &candidates,vector<vector<int>> &ans,vector<int> &curr,int idx,int target){
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        for(int i = idx;i<candidates.size();i++){
            if(i>idx && candidates[i] == candidates[i-1]){
                continue;
            }
            if(candidates[i]>target){
                break;
            }
            curr.push_back(candidates[i]);
            helper(candidates,ans,curr,i+1,target-candidates[i]);
            curr.pop_back();
            
            
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> curr;
        vector<vector<int>> ans;
        helper(candidates,ans,curr,0,target);
        return ans;
    }
};