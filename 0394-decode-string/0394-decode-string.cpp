class Solution {
public:
    string solve(int &i,string &s){
        int n=s.size();
        string ans="";
        int num=0;
        while(i<n){    
            char c=s[i];
            if(isdigit(c)){
               num=num*10+(c-'0');
               i++;
            }
            else if(c=='['){
                i++;
                string temp=solve(i,s);
                for(int k=0;k<num;k++){
                   ans+=temp;
                }
                num=0;
            }
            else if(c==']'){
                i++;
                return ans;
            }
            else{
                ans+=c;
                i++;
            }
        }    
        
        return ans;
    }
    string decodeString(string s) {
        int n=s.size();
        int i=0;
        return solve(i,s);
    }
};