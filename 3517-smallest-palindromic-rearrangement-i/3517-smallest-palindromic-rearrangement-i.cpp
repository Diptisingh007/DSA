class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        string s1,s2,ans;
        if(n%2==0){
         s1=s.substr(0,n/2);
         s2=s.substr(n/2,n);
        }
        else{
         s1=s.substr(0,n/2);
         s2=s.substr(n/2+1,n);
        }
        sort(s1.begin(),s1.end());
        sort(s2.rbegin(),s2.rend());
        if(n%2==0) ans=s1+s2;
        else ans=s1+s[n/2]+s2;

        return ans;
    }
};