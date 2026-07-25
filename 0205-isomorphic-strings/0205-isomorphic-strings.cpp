class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n!=m) return false;
        unordered_map<char,char> mpp_st;
        unordered_map<char,char> mpp_ts;

        for(int i=0;i<n;i++){
            char c1=s[i];
            char c2=t[i];
            if(mpp_st.contains(c1) && mpp_st[c1]!=c2){
                return false;
            }
            if(mpp_ts.contains(c2) && mpp_ts[c2]!=c1){
                return false;
            }
            mpp_st[c1]=c2;
            mpp_ts[c2]=c1;
        }
        return true;
    }
};