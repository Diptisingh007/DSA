class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int k=nums[0];
        for(int i=0;i<n;i++){
            if(k==nums[i]){
                k++;
            }
            else{
                ans.push_back(k);
                k++;
                i--;
            }
        }   

        return ans;
    }
};