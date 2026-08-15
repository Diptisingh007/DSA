class Solution {
public:
    string removeDuplicates(string s) {
        int n=s.size();
        string ans="";

        ans=ans+s[0];
        for(int i=1;i<n;i++){
            if( !ans.empty() && ans.back()==s[i]){
                ans.pop_back();
            }
            else{
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};