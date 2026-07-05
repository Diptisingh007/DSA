class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n<m) return "";
        int sind=-1;
        map<char,int> mpp;
        for(auto &it: t){
            mpp[it]++;
        }

        int r=0,l=0;
        int cnt=0;
        int minlen=INT_MAX;
        while(r<n){
            if(mpp[s[r]]>0) cnt++;
            mpp[s[r]]--;

            while(cnt==m){
                if(minlen > r-l+1){
                   sind=l; 
                   minlen=min(minlen,r-l+1);
                }

                mpp[s[l]]++;
                if(mpp[s[l]]>0) cnt--;
                l++;
            }
            r++;
        }

        if(sind==-1) return "";
        return s.substr(sind,minlen);
    }
};
