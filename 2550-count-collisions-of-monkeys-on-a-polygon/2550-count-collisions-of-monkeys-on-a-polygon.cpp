class Solution {
public:
    int monkeyMove(int n) {
        long mod=1e9+7;
        long ans=1;
        long base=2;
        while(n){
            if(n%2==1){
                ans=ans*base%mod;
            }

            base=base*base%mod;
            n=n/2;
        }

        return (ans-2+mod)%mod;;
    }
};