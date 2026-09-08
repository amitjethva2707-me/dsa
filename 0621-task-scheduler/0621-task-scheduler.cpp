class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(char ch : tasks){
            freq[ch-'A']++;
        }
        int maxfreq = 0;
      
        for(int f : freq){
            maxfreq = max(maxfreq,f);
        }
        int cntmax = 0;
        for(int f : freq){
            if(f == maxfreq){
                cntmax++;
            }
        }
    
         int result = (maxfreq-1)*(n+1)+cntmax;
         return max((int)tasks.size(),result);
    }
};