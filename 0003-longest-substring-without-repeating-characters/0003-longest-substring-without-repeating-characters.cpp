class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        vector<int> freq(256,-1);
        int l=0,r=0;
        int ans=0;
        while(r<n){
            if(freq[s[r]]!=-1 && l<=freq[s[r]]){
                l=freq[s[r]]+1;
            }
            ans=max(ans,r-l+1);
            freq[s[r]]=r;
            r++;
        }
        return ans;
    }
};