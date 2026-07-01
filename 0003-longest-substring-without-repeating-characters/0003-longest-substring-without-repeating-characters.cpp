class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        vector<int> freq(256,0);
        int l=0,r=0;
        int ans=0;
        while(r<n){
            while(l<r && freq[s[r]]>0){
                freq[s[l]]=0;
                l++;
            }

            freq[s[r]]=1;
            ans=max(ans,r-l+1);
            r++;
        }

        return ans;

    }
};