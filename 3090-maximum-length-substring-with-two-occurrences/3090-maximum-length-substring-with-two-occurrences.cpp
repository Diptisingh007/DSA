class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        unordered_map<char,int> mpp;
        int l=0,r=0;
        int ans=0;
        while(r<n){
            mpp[s[r]]++;
            while(l<r && mpp[s[r]]>2){
                mpp[s[l]]--;
                if(mpp[s[l]]==0){
                    mpp.erase(s[l]);
                }
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }

        return ans;
    }
};