class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0,prod=1;
        int m=n;
        while(m){
            int a=m%10;
            sum+=a;
            prod*=a;
            m=m/10;
        }
        if(n%(sum+prod)==0) return true;
        return false;
    }
};