class Solution {
public:
    int trap(vector<int>& height) {
      stack<int> st;
      int ans = 0;
      for(int i =0;i<height.size();i++){
        while(!st.empty() && height[i]>height[st.top()]){
            int top = st.top();
            st.pop();
            if(st.empty()){
                break; // no left bounadry
            }
            int left = st.top();
            int wallheight = min(height[left],height[i])-height[top];
            int width= i-left-1;
            ans  += wallheight*width;

        }
        st.push(i);
      }
      return ans;
    }
};