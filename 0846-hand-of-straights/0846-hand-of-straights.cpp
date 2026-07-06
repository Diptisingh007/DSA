class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int m) {
        int n=nums.size();
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }

        while(!mpp.empty()){
            int a=mpp.begin()->first;
            for(int i=0;i<m;i++){
                if(!mpp.contains(a+i)) return false;
                mpp[a+i]--;
                if(mpp[a+i]==0){
                    mpp.erase(a+i);
                }
            }
        }

        return true;
    }
};