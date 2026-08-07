class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n,0), right(n,0);
        stack<int> s;

        // NSR
        for(int i = n-1; i >= 0; i--){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        while(!s.empty()) s.pop();

        // NSL
        for(int i = 0; i < n; i++){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            int curr = heights[i] * (right[i] - left[i] - 1);
            ans = max(ans, curr);
        }

        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n == 0) return 0;
        int m = matrix[0].size();

        // Step 1: prefix sum (row-wise)
        vector<vector<int>> psum(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1') sum++;
                else sum = 0;
                psum[i][j] = sum;
            }
        }

        int maxi = 0;

        // Step 2: column-wise histogram
        for(int j = 0; j < m; j++){
            vector<int> temp(n);

            for(int i = 0; i < n; i++){
                temp[i] = psum[i][j];
            }

            maxi = max(maxi, largestRectangleArea(temp));
        }

        return maxi;
    }
};