class Solution {
public:
    string solve(int left,int right, string &s,int &cnt){
        int n=s.size();
        while(left>=0 && right<n && s[left]==s[right]){
            left--;
            right++;
            cnt++;
        }
        return s.substr(left+1,right-left-1);
    }
    int longestPalindrome(string s){
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            string odd=solve(i,i,s,ans);
            string even=solve(i,i+1,s,ans);
        }
        return ans;
    }
    int countSubstrings(string s) {
        return longestPalindrome(s);
    }
};