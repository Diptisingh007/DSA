class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        if(n%2!=0) return false;
        stack<char> st;
        for(auto &it: s){
            if(it=='(' || it=='[' || it=='{') st.push(it);
            else{
                if(!st.empty()){
                    char c=st.top();
                    if((c=='(' && it==')') || (c=='{' && it=='}') || (c=='[' && it==']')){
                       st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }

        return st.empty();
    }
};