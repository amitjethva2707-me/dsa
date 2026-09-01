class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int total =0;
        for(int x : cardPoints){
            total += x;
        }
        int n = cardPoints.size();
        int winsize = n-k;
        if(winsize == 0){
            return total;
        }
        int wintotal = 0;
        for(int i =0;i<winsize;i++){
            wintotal += cardPoints[i];
        }
        int mintotal = wintotal;
        for(int i = winsize;i<n;i++){
            wintotal += cardPoints[i];
            wintotal -= cardPoints[i-winsize];
            mintotal = min(mintotal,wintotal);
        }
        return total-mintotal;
    }
};