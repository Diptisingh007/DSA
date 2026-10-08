class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        int cnt=0;
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]==')') cnt--;
            if(cnt!=0) ans=ans+s[i];
            if(s[i]=='(') cnt++;
        }
        return ans;
    }
};