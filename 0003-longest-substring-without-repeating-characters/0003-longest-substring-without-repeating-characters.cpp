class Solution {
public:
    // int lengthOfLongestSubstring(string s) {
    //     int n=s.size();
    //     vector<int> freq(256,0);
    //     int l=0,r=0;
    //     int ans=0;
    //     while(r<n){
    //         while(l<r && freq[s[r]]>0){
    //             freq[s[l]]=0;
    //             l++;
    //         }
    //         freq[s[r]]=1;
    //         ans=max(ans,r-l+1);
    //         r++;
    //     }
    //     return ans;
    // }
    
    int lengthOfLongestSubstring(string s){
        int n=s.size();
        vector<int> freq(256,-1);
        int l=0,r=0;
        int ans=0;
        while(r<n){
            if(freq[s[r]]>=0){
                if(freq[s[r]]>=l){
                    l=freq[s[r]]+1;
                }
            }

            ans=max(ans,r-l+1);
            freq[s[r]]=r;
            r++;
        }

        return ans;
    }

};