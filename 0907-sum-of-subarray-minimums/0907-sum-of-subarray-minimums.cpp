class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
      const long long MOD = 1e9 + 7;
        long long ans = 0;
        int n = arr.size();
          vector<int> left(n);
        vector<int> right(n);
        stack<int> s;
        for(int i =0;i<n;i++){
            while(!s.empty() && arr[s.top()]>arr[i]){
                s.pop();
            }   
            if(s.empty()){
                left[i] = i+1;
            } else {
                left[i] = i-s.top();
            }
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }
        for(int i = n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]>=arr[i]){
                s.pop();
            }
            if(s.empty()){
                right[i] = n-i;
            } else{
                right[i] = s.top()-i;
            }
            s.push(i);
        }
        for(int i =0;i<n;i++){
            long long con = (long long)arr[i]*(right[i]*left[i]);
            ans  = (ans+con)%MOD;
        }
        return ans;
    }
};