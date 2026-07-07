class Solution {
public:
    long long sumAndMultiply(int n) {
        string s=to_string(n);

        long long ans=0,sum=0;
        for(auto &it: s){
            int digit=it-'0';
            if(digit!=0){
                sum+=digit;
                ans=ans*10+digit;
            }
        }

        ans=ans*sum;
        return ans;
    }
};