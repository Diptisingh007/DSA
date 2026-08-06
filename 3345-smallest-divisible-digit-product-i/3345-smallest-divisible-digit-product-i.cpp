class Solution {
public:
    int product(int n){
        int ans=1;
        while(n){
            int dig=n%10;
            ans=ans*dig;
            n=n/10;
        }
        return ans;
    }
    int smallestNumber(int n, int t) {
        
        while(true){
            int ele=product(n);
            if(ele%t==0) return n;
            n++;
        }

        return -1;
    }
};