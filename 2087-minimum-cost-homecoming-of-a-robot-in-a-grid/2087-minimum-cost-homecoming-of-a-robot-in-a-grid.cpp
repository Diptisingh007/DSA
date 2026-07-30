class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int n=rowCosts.size();
        int m=colCosts.size();
        int ans=0;

        int i=startPos[0];
        int j=homePos[0];
        
        if(i<j){
            while(i<j){
              ans=ans+(rowCosts[i+1]);
              i++;
            }
        }
        else{
            while(i>j){
              ans=ans+(rowCosts[i-1]);
              i--;
            }
        }


        i=startPos[1];
        j=homePos[1];
        if(i<j){
            while(i<j){
              ans=ans+(colCosts[i+1]);
              i++;
            }
        }
        else{
            while(i>j){
              ans=ans+(colCosts[i-1]);
              i--;
            }
        }

        return ans;
    }
};