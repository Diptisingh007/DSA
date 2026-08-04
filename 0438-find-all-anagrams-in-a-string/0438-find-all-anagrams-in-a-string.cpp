class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        int m=p.size();
        unordered_map<char,int> mpp;
        for(auto &it:p){
            mpp[it]++;
        }

        int l=0,r=0;
        int cnt=0;
        vector<int> ans;
        while(r<n){
            if(mpp[s[r]]>0) cnt++;
            mpp[s[r]]--;

            while(l<r && (r-l+1)>m){
                if(mpp[s[l]]>=0) cnt--;
                mpp[s[l]]++;
                l++;
            }
            if(cnt==m){
                ans.push_back(l);
            }
            r++;
        }

        return ans;
    }
};