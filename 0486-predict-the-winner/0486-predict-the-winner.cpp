class Solution {
public:
    bool solve(int i, int j, vector<int>&nums,int p1, int p2, int turn){
        int n=nums.size();
        if(i>j){
            return p1>=p2;
        }

        if(turn){
            return solve(i+1,j,nums,p1+nums[i],p2,!turn) || solve(i,j-1,nums,p1+nums[j],p2,!turn);
        }
        return solve(i+1,j,nums,p1,p2+nums[i],!turn) && solve(i,j-1,nums,p1,p2+nums[j],!turn);

    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        return solve(0,n-1,nums,0,0,1);
    }
};