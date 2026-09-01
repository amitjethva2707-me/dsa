class Solution {
public:
bool f(int cnt[]){
    return cnt[0]>0 && cnt[1]>0 && cnt[2]>0;

}
    int numberOfSubstrings(string s) {
     int n = s.size();
     int i =0;
     int ans = 0;
     int cnt[3] = {0};   
     for(int j = 0;j<n;j++){
        cnt[s[j]-'a']++;
        while(f(cnt)){
            ans += n-j;
            cnt[s[i]-'a']--;
            i++;
        }
     }
     return ans;
    }
};