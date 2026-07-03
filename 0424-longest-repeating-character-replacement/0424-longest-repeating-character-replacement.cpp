class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int l=0,r=0;
        int maxlen=0,maxfreq=0;
        vector<int> freq(26,0);

        while(r<n){
            freq[s[r]-'A']++;
            maxfreq=max(maxfreq,freq[s[r]-'A']);

            int len=r-l+1;
            while((len-maxfreq)>k){
                freq[s[l]-'A']--;
                maxfreq=0;
                for(int i=0;i<26;i++){
                    maxfreq=max(maxfreq,freq[i]);
                }
                l++;
                len=r-l+1;
            }

            maxlen=max(maxlen,len);
            r++;
        }
        return maxlen;
    }
};