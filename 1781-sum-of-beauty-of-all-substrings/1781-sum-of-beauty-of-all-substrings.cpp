class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int mini=INT_MAX;
            int maxi=INT_MIN;
            vector<int> freq(26,1e9);
            for(int j=i;j<n;j++){
                int ind=s[j]-'a';
                if(freq[ind]==1e9) freq[ind]=1;
                else freq[ind]++;
                maxi=max(maxi,freq[ind]);
                mini=*min_element(freq.begin(),freq.end());
                ans+=(maxi-mini);
            }
        }

        return ans;
    }
};