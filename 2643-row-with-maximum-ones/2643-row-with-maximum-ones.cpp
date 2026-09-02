class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxi = -1;
        int idx = 0;
        vector<int> ans;
        int m = mat.size();
        int n = mat[0].size();
        int temp;
        for (int i = 0; i < m; i++) {
            temp =0;
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    temp++;
                }
            }
            if (temp > maxi) {
                maxi = temp;
                idx =i;
            }
        }
        return {idx,maxi};
    }
};