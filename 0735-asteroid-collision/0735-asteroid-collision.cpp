class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr;

        for(int i=0;i<n;i++){
            if(nums[i] > 0){
                arr.push_back(nums[i]);
            }
            else{
                while(arr.size()>0 && arr.back()>0 && abs(arr.back()) < abs(nums[i])){
                    arr.pop_back();
                }

                if(arr.size()>0 && arr.back()>0 && arr.back()==abs(nums[i])){
                    arr.pop_back();
                }
                else if(arr.size()==0 || arr.back() < 0){
                    arr.push_back(nums[i]);
                }
            }
        }

        return arr;
    }
};