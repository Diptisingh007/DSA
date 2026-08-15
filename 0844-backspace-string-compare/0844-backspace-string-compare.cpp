class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n=s.size();
        int m=t.size();
        string s1,t1;
        for(int i=0;i<n;i++){
            if(!s1.empty() && s[i]=='#'){
                s1.pop_back();
            }
            else if(s[i]!='#'){
                s1.push_back(s[i]);
            }
        }
        for(int i=0;i<m;i++){
            if(!t1.empty() && t[i]=='#'){
                t1.pop_back();
            }
            else if(t[i]!='#'){
                t1.push_back(t[i]);
            }
        }

        if(s1==t1) return true;
        return false;
    }
};