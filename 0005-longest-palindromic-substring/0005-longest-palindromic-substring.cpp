class Solution {
public:
    // bool pal(int left, int right, string &s){
    //     while(left<=right && s[left]==s[right]){
    //         left++;
    //         right--;
    //     }
    //     if(left>right) return true;
    //     return false;
    // }
    // string longestPalindrome(string s) {
    //     int n=s.size();
    //     string ans="";
    //      for(int i=0;i<n;i++){
    //         for(int j=i;j<n;j++){
    //             if(pal(i,j,s) && ans.size()<(j-i+1)){
    //                 ans=s.substr(i,j-i+1);
    //             }
    //         }
    //      }

    //      return ans;
    // }

    
    string solve(int left,int right, string &s){
        int n=s.size();

        while(left>=0 && right<n && s[left]==s[right]){
            left--;
            right++;
        }

        return s.substr(left+1,right-left-1);
    }
     string longestPalindrome(string s){
        int n=s.size();
        string ans;
        for(int i=0;i<n;i++){
            string odd=solve(i,i,s);
            if(odd.size()>ans.size()) ans=odd;
            string even=solve(i,i+1,s);
            if(even.size()>ans.size()) ans=even;
        }
        return ans;
     }

};