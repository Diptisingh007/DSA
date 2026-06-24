class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign=1;
        if(dividend==divisor) return 1;
        long long n=abs((long long)dividend);
        long long d=abs((long long)divisor);

        if(dividend>0 && divisor<0) sign=-1;
        if(dividend<0 && divisor>0) sign=-1;
        long long ans=0;
        while(n>=d){
            long long cnt=0;
            while(n>=(d<<(cnt+1))) cnt++;
            ans+=(1LL<<cnt);
            n=n-(d*(1LL<<cnt));
        }

        if(ans*sign<=INT_MIN) return INT_MIN;
        if(ans*sign>=INT_MAX) return INT_MAX;

        return (int)(ans*sign);
    }
};