class Solution {
public:
    int arrangeCoins(int n) {
        
        int ans=0;
        int cnt=1;
        while(n>=cnt){
            n=n-cnt;
            cnt++;
            ans++;
        }

        return ans;
    }
};