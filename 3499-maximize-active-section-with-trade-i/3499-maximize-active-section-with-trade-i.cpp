class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones=0;
        for(auto &it:s){
            if(it=='1') ones++;
        }

        int ans=ones;
        s='1'+s+'1';
        int n=s.size();
        int i=0;

        while(i<n && s[i]=='1'){
            i++;
        }

        int left_zero=0;

        while(i<n && s[i]=='0'){
            i++;
            left_zero++;
        }
        while(i<n){

            int middle_one=0;
            while(i<n && s[i]=='1'){
              middle_one++;
              i++;
            }
            if(middle_one==0) break;

            int right_zero=0;
            while(i<n && s[i]=='0'){
               right_zero++;
               i++;
            }
            if(right_zero==0) break;

            ans=max(ans,ones+left_zero+right_zero);

            left_zero=right_zero;
        }

        return ans;
    }
};