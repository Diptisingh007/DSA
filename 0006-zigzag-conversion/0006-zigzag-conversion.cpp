class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.size();
        if(numRows==1 || numRows>=n) return s;
        
        vector<vector<char>> arr(numRows);
        int i=0,d=1;
        for(auto &it: s){
            arr[i].push_back(it);

            if(i==0) d=1;
            if(i==numRows-1) d=-1;

            i+=d;
        }

         string ans="";
         for(auto &it: arr){
              for(auto &c: it){
                ans.push_back(c);
              }
         }

         return ans;


    }
};