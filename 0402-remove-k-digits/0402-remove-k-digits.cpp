class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        string s;
        
        for(int i=0;i<n;i++){
            while(!s.empty() && s.back() > num[i] && k>0){
                s.pop_back();
                k--;
            }
            s.push_back(num[i]);
        }
        while(!s.empty() && k>0){
            s.pop_back();
            k--;
        }
        int i=0;
        while( i<s.size() && s[i]=='0'){
            i++;
        }
        
        string ans=s.substr(i);
        return ans.empty() ? "0" : ans; 
    }
};