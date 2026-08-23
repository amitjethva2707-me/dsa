class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
          const long long MOD = 1e9 + 7;
        long long ans = 0;
        int n = arr.size();
        // LEFT  → previous smaller OR EQUAL
// RIGHT → next strictly smaller
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
            ans  = (ans+con);
        }
        
          vector<int> left1(n);
        vector<int> right1(n);
        stack<int> s1;
        for(int i =0;i<n;i++){
            while(!s1.empty() && arr[s1.top()]<=arr[i]){
                s1.pop();
            }   
            if(s1.empty()){
                left1[i] = i+1;
            } else {
                left1[i] = i-s1.top();
            }
            s1.push(i);
        }
        while(!s1.empty()){
            s1.pop();
        }
        for(int i = n-1;i>=0;i--){
            while(!s1.empty() && arr[s1.top()]<arr[i]){
                s1.pop();
            }
            if(s1.empty()){
                right1[i] = n-i;
            } else{
                right1[i] = s1.top()-i;
            }
            s1.push(i);
        }
        long long ans1 = 0;
        for(int i =0;i<n;i++){
            long long con = (long long)arr[i]*(right1[i]*left1[i]);
            ans1  = (ans1+con);
        }
        return ans1-ans;
        
    }
};