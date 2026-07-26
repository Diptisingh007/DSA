class Solution {
public:
    double myPow(double x, int n) {
        long power=n;
        if(power<0){
            x=1/x;
            power=-power;
        }
        
        double ans=1;
        while(power){
            if(power%2==1){
                ans=ans*x;
                power--;
            }
          
          x=x*x;
          power=power/2;
        }

        // if(power==1){
        //     ans=ans*x;
        // }

        return ans;
    }
};