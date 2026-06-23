class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        long long ans=0;
        int sign=1;
        int i=0;
        while(i<n && s[i]==' '){
            i++;
        }
        if(s[i]=='+' || s[i]=='-'){
            if(s[i]=='-'){
                sign=-1;
            }
            i++;
        }

        while(i<n && isdigit(s[i])){
            ans=ans*10+(s[i]-'0');
            i++;
            if(ans*sign>=INT_MAX) return INT_MAX;
            if(ans*sign<=INT_MIN) return INT_MIN;
        }

        return (int)ans*sign;

    }
};