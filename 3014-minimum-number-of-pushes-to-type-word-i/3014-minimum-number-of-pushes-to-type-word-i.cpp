class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int ans=0;
        int cnt=1;
        while(n){
            if(n<=8){
             ans+=(n*cnt);
             n=n-n;
            }
            else{
              ans+=(8)*cnt;
              n=n-8;
              cnt++;
            }
        }

        return ans;
    }
};