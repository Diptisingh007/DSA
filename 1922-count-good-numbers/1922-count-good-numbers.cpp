class Solution {
public:
    int mod=(1e9+7);
    long long pow(long long a, long long b){
        if(b==0) return 1;
        int ans=1;

        while(b){
            if(b%2==1){
                ans=(ans*a)%mod;
                b--;
            }

            a=(a*a)%mod;
            b=b/2;
        }
        // if(b==1) ans=(ans*a)%mod;

        return ans%mod;
    }
    int countGoodNumbers(long long n) {
        long long  odd=n/2;
        long long even=(n+1)/2;

        
       long long a=pow((long long)5,even);
       long long b=pow((long long)4,odd);
        
        return (long long)(a*b)%mod;
    }
};