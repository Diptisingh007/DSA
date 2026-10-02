class Solution {
public:
    void solve(int n,vector<string>&ans, string &s, int open, int close){
        if(s.size()==2*n){
            ans.push_back(s);
            return;
        }

        if(open<n){
            s.push_back('(');
            solve(n,ans,s,open+1,close);
            s.pop_back();
        }

        if(close<open){
            s.push_back(')');
            solve(n,ans,s,open,close+1);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s="";
        solve(n,ans,s,0,0);
        return ans;
    }
};