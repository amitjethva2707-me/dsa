class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> after(2,vector<int>(3,0));
        vector<vector<int>> curr (2,vector<int>(3,0));
        for(int i = prices.size()-1;i>=0;i--){
            for(int buy =0;buy<=1;buy++){
               for(int cnt =1;cnt<= 2;cnt++){
                if(buy ==1){
                    curr[buy][cnt] = max(-prices[i]+after[0][cnt],after[1][cnt]);
                } else {
                    curr[buy][cnt] = max(prices[i]+after[1][cnt-1],after[0][cnt]);
                }
               }
            }
            after = curr;
        }
        return (int)after[1][2];
    }
};