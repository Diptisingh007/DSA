class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.size();

        int open=0;
        int close=0;
        for(auto &it: s){
            if(it=='(') open++;
            else if(it==')' && open>0) open--;
            else close++;
        }

        return abs(open+close);
    }
};