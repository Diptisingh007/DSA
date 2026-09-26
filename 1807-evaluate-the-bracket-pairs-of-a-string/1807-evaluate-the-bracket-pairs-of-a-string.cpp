class Solution {
public:
    string evaluate(string s, vector<vector<string>>& nums){
        int n=s.size();
        unordered_map<string,string> mpp;
        for(auto &it:nums){
            mpp[it[0]]=it[1];
        }

        string ans;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                int j=s.find(')',i+1);
                string t=s.substr(i+1,j-i-1);
                if(mpp.find(t)!=mpp.end()){
                    ans+=mpp[t];
                }
                else{
                    ans+='?';
                }
                i=j;
            }
            else{
                ans+=s[i];
            }
        }

        return ans;
    }
};